class Solution {
public:
    int _find(vector<int>& ds, int x) { 
        if (ds[x] == -1) return x;
        return ds[x] = _find(ds, ds[x]);    /* path compression */
    }
    void _union(vector<int>& ds, int x, int y, int& a)
    {
        int _x = _find(ds, x), _y = _find(ds, y);
        if (_x != _y) { ds[_x] = _y; a++; ds[0]++; }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> ds(n + 1, -1), tmp; int r = 0, i = 0;
        ds[0] = 0;  /* use this to store set element count in disjoint array */
        while(i < 3) {
            for (auto e : edges) if (e[0] == 3 - i /* type */) _union(ds, e[1], e[2], r);
            if (i) if (n - 1 != ds[0]) return -1;  /* check if set holds all nodes 1..4 */
            if (++i%2) tmp = ds; else ds = tmp;
        }
        return edges.size()     /* edges of all types, including some redundant ones */
                        - r;    /* required edges of type 3, 2 and 1 */
    }
};
