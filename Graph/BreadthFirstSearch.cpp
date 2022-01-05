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
    bool visited[g.size()];
    for(int i = 0; i < g.size(); i++)
    {
        visited[i] = false;
    }

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