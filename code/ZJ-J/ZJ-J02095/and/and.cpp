#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 2e5 + 10;
struct trie
{
	private:
	struct treenode
	{
		int val;
		treenode* l;
		treenode* r;
		treenode() : val(0), l(nullptr), r(nullptr){}
	};
	treenode pool[MAXN * 32];
	treenode* root;
	int c = 0;
	inline treenode* new_treenode(){return &pool[c++];}
	inline int val(treenode* node){return node == nullptr ? 0 : node->val;}
	inline treenode* merge(treenode* x, treenode* y)
	{
		if(x == nullptr)return y;
		if(y == nullptr)return x;
		x->val += y->val;
		x->l = merge(x->l, y->l);
		x->r = merge(x->r, y->r);
		return x;
	}
	inline treenode* add_x(treenode* node, int p, int depth = 30)
	{
		if(node == nullptr)node = new_treenode();
		if(depth == -1){node->val++; return node;}
		if((p >> depth) & 1)node->r = add_x(node->r, p, depth - 1);
		else node->l = add_x(node->l, p, depth - 1);
		node->val = val(node->l) + val(node->r);
		return node;
	}
	inline int answer_x(treenode* node, int m, int depth = 30)
	{
		if(node == nullptr)return 0;
		if(depth == -1)return 0;
		if(val(node->r) < m)node->l = merge(node->l, node->r), node->r = nullptr;
		if(!val(node->r))return answer_x(node->l, m, depth - 1);
		else return answer_x(node->r, m, depth - 1) + (1LL << depth);
	}
	public:
	inline void add(int p){root = add_x(root, p);}
	inline int answer(int m){return answer_x(root, m);}
}f;
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		f.add(x);
	}
	cout << f.answer(m);
}