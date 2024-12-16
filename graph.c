#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node {  // to represent vertex and edge
    int data;
    int status;
    struct node *next, *point;
} node;

typedef struct topsort {  // to represent vertices of topological sort
    int n;
    struct topsort *next;
} topsort;

int d[SIZE], f[SIZE], time;
node *q[SIZE];  // to maintain queue
int front = 0, rear = 0;  // queue handling pointers
node *g = NULL;  // to store graph
topsort *tsort = NULL;  // to store topological sort order

// function to add a vertex
void addvertex(int n) {
    node *t = (node*)malloc(sizeof(node));
    t->data = n;
    t->point = NULL;
    t->next = g;
    g = t;
}

// function to find vertex node address of a vertex
node* find(int n) {
    node *t = g;
    while(t != NULL && t->data != n)
        t = t->next;
    return t;
}

// function to add an edge
void addedge(int u, int v) {
    node *v1 = find(u), *v2 = find(v), *t;
    if (!v1 || !v2) return;
    
    t = (node*)malloc(sizeof(node));
    t->next = v1->point;
    v1->point = t;
    t->point = v2;
}

// function to print a graph
void printgraph() {
    node *t1, *t2, *t3;
    printf("\n Vertex\tEdge List\n");
    t1 = g;
    while(t1 != NULL) {
        printf("\n %d....\t", t1->data);
        t2 = t1->point;
        while(t2 != NULL) {
            t3 = t2->point;
            printf("%d,", t3->data);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}

// inserting nodes in topological order list at beginning
void topsorting(int n) {
    topsort *z = (topsort*)malloc(sizeof(topsort));
    z->n = n;
    z->next = tsort;
    tsort = z;
}

// printing topological order list
void topsortout() {
    while(tsort != NULL) {
        printf("%d,", tsort->n);
        tsort = tsort->next;
    }
}

// dfs-visit
void dfs_visit(node *u) {
    node *t, *t1;
    u->status = 1;  // visit vertex
    printf("%d,", u->data);
    ++time;
    d[u->data] = time;  // store discovery time
    t = u->point;
    while(t != NULL) {
        t1 = t->point;
        if(t1->status == 0)  // if not visited
            dfs_visit(t1);
        t = t->next;
    }
    ++time;
    f[u->data] = time;  // store finish time
    topsorting(u->data);  // store the node topological sort list
}

// dfs search
void dfs(node *g1) {
    node *t = g;
    while(t != NULL) {
        t->status = 0;  // set as not visited
        t = t->next;
    }
    dfs_visit(g1);
}

// enqueue operation
void enque(node *s) {
    int r1 = (rear + 1) % SIZE;
    if (r1 == front) {
        printf("Queue is full\n");
        exit(1);
    }
    rear = r1;
    q[rear] = s;
}

// emptyq-to test queue is empty or not
int emptyq() {
    return front == rear;
}

// dequeue operation
node* dequeue() {
    if(emptyq()) {
        printf("Queue is empty\n");
        exit(2);
    }
    front = (front + 1) % SIZE;
    return q[front];
}

// bfs
void bfs(node *s) {
    node *t = g, *t1, *u;
    while(t != NULL) {
        t->status = 0;  // set all vertices as not visited
        t = t->next;
    }
    
    s->status = 1;  // visit start vertex
    printf("%d,", s->data);
    enque(s);
    
    while(!emptyq()) {
        u = dequeue();
        t = u->point;
        while(t != NULL) {
            t1 = t->point;
            if(t1->status == 0) {
                printf("%d,", t1->data);
                t1->status = 1;
                enque(t1);
            }
            t = t->next;
        }
    }
}

int main() {
    // Graph Construction
    addvertex(1);
    addvertex(2);
    addvertex(3);
    addvertex(4);
    addvertex(5);
    
    // Adding edges
    addedge(1, 2);
    addedge(1, 4);
    addedge(2, 3);
    addedge(2, 4);
    addedge(4, 3);
    addedge(4, 5);
    
    // Print graph
    printf("The graph is:\n");
    printgraph();
    
    // DFS Traversal
    printf("\nDFS traverse: ");
    dfs(find(1));
    
    // BFS Traversal
    printf("\nBFS traverse: ");
    bfs(find(1));
    
    // Topological Sort Output
    printf("\nTopological Sort order is: ");
    topsortout();
    
    return 0;
}

