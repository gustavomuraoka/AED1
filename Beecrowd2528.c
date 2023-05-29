#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start, int destination);

void Dijkstra(int Graph[MAX][MAX], int n, int start, int destination) {
  
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i == destination) {
      printf("\n%d", distance[i-1]);
    }


}
int main() {
 
  int n, m;
  scanf("%d %d", &n, &m);

  while (1) {

    int Graph[n][n];
    int routestart, routearrive;

    for (int i = 0; i < m; i++) {
      scanf("%d %d", &routestart, &routearrive);
      Graph[routestart-1][routearrive-1] = 1;
      Graph[routearrive-1][routestart-1] = 1;
    }
  
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++) {
        if (Graph[i][j] != 1) {
          Graph[i][j] = 0;
        }
      }
    }

    /*for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++) {
        printf("%d ", Graph[i][j]);  
      }
      printf("\n");
    }*/

    int c, r, e;

    scanf("%d %d %d", &c, &r, &e);

    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++) {
        if (i == e-1 || j == e-1) {
          Graph[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++) {
        printf("%d ", Graph[i][j]);  
      }
      printf("\n");
    }


    Dijkstra(Graph, n, c-1, r);

  }

  //n = 7;    
  //u = 0;

  

  return 0;
}