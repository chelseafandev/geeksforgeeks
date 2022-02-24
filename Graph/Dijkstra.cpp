#include <iostream>
#include <limits.h>

#define NUMBER_OF_VERTICES 9

int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < NUMBER_OF_VERTICES; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES], int src)
{
    // 출발지에서 i까지의 최단 거리를 저장하는 배열
    int dist[NUMBER_OF_VERTICES];

    // 버텍스 i가 최소 신장 트리에 포함되어있거나 출발지에서 버텍스 i까지의 최소 거리를 구한 경우에는 sptSet[i]값이 true
    bool sptSet[NUMBER_OF_VERTICES];

    // dist 및 sptSet 배열 초기화(dist는 매우 큰값으로, stpSet은 false)
    for (int i = 0; i < NUMBER_OF_VERTICES; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // dist[src](자기 자신) 값은 항상 0
    dist[src] = 0;

    // 모든 버텍스들에 대해 최단 거리를 구한다
    for (int count = 0; count < NUMBER_OF_VERTICES - 1; count++)
    {
        // 1. 아직 처리되지 않은 버텍스들의 집합에서 가장 최소 거리를 갖는 버텍스를 선택
        int u = minDistance(dist, sptSet);

        // 2. 처리가 된 버텍스는 마킹
        sptSet[u] = true;

        // 3. 선택된 버텍스의 인접한 버텍스들의 dist 값 업데이트
        for (int v = 0; v < NUMBER_OF_VERTICES; v++)
        {
            // dist[v] 값은 버텍스 v가 sptSet에 포함되어있지 않고 버텍스 u에서 v까지의 edge가 존재하며,
            // 출발지에서 u를 거쳐 v로 가는 경로의 총 가중치가 dist[v]의 현재 값보다 더 작은 경우에만 업데이트
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

// using priority queue
void dijkstra_ver2(int graph[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES], int src)
{
    
}

int main()
{
    // 인접행렬로 그래프를 표현(행:출발지 열:도착지)
    int graph[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES] = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0} 
        };

    dijkstra(graph, 0);
    return 0;
}