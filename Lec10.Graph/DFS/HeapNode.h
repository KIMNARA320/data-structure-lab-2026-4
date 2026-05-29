//HeapNode.h
class HeapNode {
	int key;
	int v1;
	int v2;
public:
	HeapNode(int k, int u, int v) : key(k), v1(u), v2(v) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	int getV1() { return v1; }
	int getV2() { return v2; }
};
