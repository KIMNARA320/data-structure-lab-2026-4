#pragma once
struct Location2D {
    int row;
    int col;
    Location2D(int r = 0, int c = 0) { row = r; col = c; }
    bool isNeighber(const Location2D& p) {
        return ((row == p.row && (col == p.col - 1 || col == p.col + 1))
            || (col == p.col && (row == p.row - 1 || row == p.row + 1)));
    }
    bool operator==(const Location2D& p) {
        return row == p.row && col == p.col;
    }
};

#define INF 9999

class WGraph : public AdjMatGraph {
public:
    void insertEdge(int u, int v, int weight) {
        if (weight > INF) weight = INF;
        setEdge(u, v, weight);
    }
    bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }

    void load(char* filename) {
        FILE* fp = fopen(filename, "r");
        if (fp != NULL) {
            int n, val;
            fscanf_s(fp, "%d", &n);
            for (int i = 0;i < n; i++) {
                char str[80];
                int val;
                fscanf_s(fp, "%s", str);
                insertVertex(str[0]);
                for (int j = 0; j < n; j++) {
                    fscanf(fp, "%d", &val);
                    insertEdge(i, j, val);
                }
            }
        }
        fclose(fp);
        //DFS Å½»ö ¹æ¹®
        printf("DFS ==>");
        g.resetVisited();
        g.DFS(0);
        printf("\n");

        Wgraph wg;
        wg.load("../graph.txt");
        wg.display();

        return 0
    }
};
