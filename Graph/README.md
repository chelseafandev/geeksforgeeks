# Graph

- [Graph](#graph)
  - [Breadth First Search or BFS for a Graph](#breadth-first-search-or-bfs-for-a-graph)
    - [Solution](#solution)
  - [Depth First Search or DFS for a Graph](#depth-first-search-or-dfs-for-a-graph)

<br>

## Breadth First Search or BFS for a Graph
원문링크: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

<br>

그래프에서 너비 우선 탐색은 트리의 너비 우선 탐색과 유사합니다. 트리와의 차이점은 그래프는 순환을 포함할 수 있다는 점입니다. 그래서 우리는 동일한 노드로 다시 돌아 올 수도 있습니다. 동일한 노드를 한번 더 처리하는 것을 피하기 위해서 방문 여부를 bool값 형태로 저장하는 배열을 사용합니다. 문제를 단순화하기 위해 모든 vertex들은 시작 지점으로부터 도달 가능하다고 가정하겠습니다.
> Breadth-First Traversal (or Search) for a graph is similar to Breadth-First Traversal of a tree. The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all vertices are reachable from the starting vertex.

예를 들어, 아래 그래프는 2번 vertex에서 탐색을 시작합니다. 0번 vertex에 도달했을때 해당 vertex에 인접한 모든 vertex들을 찾습니다. 시작 지점이었던 2번 vertex 또한 0번 vertex에 인접해있습니다. 만약 방문했던 vertex를 표시하지 않는다면 2번 vertex는 다시 한번 처리될 것이고 절대 종료되지 않는 프로세스가 되어버릴 것입니다. 아래 그래프의 너비 우선 탐색 결과는 2, 0, 3, 1 입니다.
> For example, in the following graph, we start traversal from vertex 2. When we come to vertex 0, we look for all adjacent vertices of it. 2 is also an adjacent vertex of 0. If we don’t mark visited vertices, then 2 will be processed again and it will become a non-terminating process. A Breadth-First Traversal of the following graph is 2, 0, 3, 1.

![](../resources/images/bfs-figure-1.png)

[소스로 이동](https://github.com/chelseafandev/geeksforgeeks/blob/main/Graph/BreadthFirstSearch.cpp)

<br>

### Solution

<br>

<details>
<summary>솔루션 보기</summary>
<div markdown="1">

<br>

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <set>

class graph
{
public:
    static const int CAPACITY = 100;
    
    graph()
    {
        // init
        for (int i = 0; i < CAPACITY; i++)
        {
            labels_[i] = -1;
        }

        for (int i = 0; i < CAPACITY; i++)
        {
            for (int j = 0; j < CAPACITY; j++)
            {
                edges_[i][j] = false;
            }
        }

        size_ = 0;
    }

    int size() const
    {
        return size_;
    }

    void add_vertex(int val)
    {
        if (size_ < CAPACITY)
        {
            int new_vertex_index = size_;
            size_++;
            
            // set new edge
            for(int i = 0; i < size_; i++)
            {
                edges_[new_vertex_index][i] = false;
                edges_[i][new_vertex_index] = false;
            }

            // set new vertex label
            labels_[new_vertex_index] = val;
        }
    }

    void add_edge(int src, int dst)
    {
        if(src < 0 || src >= size_)
        {
            return;
        }

        if(dst < 0 || dst >= size_)
        {
            return;
        }

        edges_[src][dst] = true;
    }

    // 인자로 전달된 vertex에 인접한 모든 vertex를 반환함
    std::set<int> neighbors(int vertex)
    {
        std::set<int> result;

        for(int i = 0; i < size_; i++)
        {
            if (edges_[vertex][i])
            {
                result.insert(i);
            }
        }

        return result;
    }

private:
    bool edges_[CAPACITY][CAPACITY];
    int labels_[CAPACITY];
    int size_;
};

void bfs(graph& g, int start)
{
    // 방문 여부를 확인하는 변수
    bool visited[g.size()];
    for(int i = 0; i < g.size(); i++)
    {
        visited[i] = false;
    }

    // 너비 우선 탐색은 큐(queue)를 사용하여 구현함
    std::queue<int> q;

    q.push(start);
    while(!q.empty())
    {
        int popped = q.front();
        visited[popped] = true;
        std::cout << popped << " ";
        q.pop();

        for (auto neighbor : g.neighbors(popped))
        {
            if(!visited[neighbor])
            {
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    graph g;
    
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    std::cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n";
    bfs(g, 2);
}
```

Ouput:
```diff
Following is Breadth First Traversal (starting from vertex 2)
2 0 3 1
```

<br>

시간복잡도: O(V+E) (V: vertex의 개수, E: edge의 개수)
> Time Complexity: O(V+E) where V is a number of vertices in the graph and E is a number of edges in the graph.

</div>
</details>

---

<br>
<br>

## Depth First Search or DFS for a Graph
