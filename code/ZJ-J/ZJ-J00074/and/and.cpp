#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int n, m;
	int a[200001];
	class trie
	{
	private:
		trie *c0, *c1;
		int chn;

	public:
		trie() : c0(nullptr), c1(nullptr), chn(0)
		{
		}
		trie(const trie &t)
		{
			// cout << "START COPY: {\n";
			// cout << " - THAT IS: \n   ";
			// t.print();
			// cout << endl;
			chn = t.chn;
			if (t.c0)
				c0 = new trie(*(t.c0));
			else
				c0 = nullptr;
			if (t.c1)
				c1 = new trie(*(t.c1));
			else
				c1 = nullptr;
			// cout << " - AFTER THAT: \n   ";
			// print();
			// cout << endl;
			// cout << "}END COPY\n";
		}
		void insert(int n, int len = 30)
		{
			assert(len > 0 || n == 0);
			++chn;
			if (len <= 0)
				return;
			trie *&ch = ((n & (1 << (len - 1))) ? c1 : c0);
			if (ch == nullptr)
				ch = new trie;
			ch->insert(n & ((1 << (len - 1)) - 1), len - 1);
		}
		int mx_and(int n, int len = 30)
		{
			// cout << "MX_AND: {\n";
			if (!c1 && !c0)
				return 0;
			if (c1)
				if (c1->chn >= n)
				{
					// cout << "  go c1\n";
					return (c1->mx_and(n, len - 1) + (1 << (len - 1)));
				}
				else
				{
					// cout << "  go tt\n  ";
					// c0->print();
					// cout << "\n  ";
					trie tt = *c0;
					// tt.print();
					// cout << "\n  ";
					tt.merge(*c1);
					// tt.print();
					// cout << endl;
					return (tt.mx_and(n, len - 1));
				}
			else
			{
				// cout << "  go c0\n";
				return (c0->mx_and(n, len - 1));
			}
		}
		void merge(const trie &t)
		{
			// cout << "START MERGE: {\n";
			// cout << " - THIS IS: \n   ";
			// print();
			// cout << "\n - THAT IS: \n   ";
			// t.print();
			// cout << endl;
			chn += t.chn;
			if (t.c0)
			{
				if (!c0)
					c0 = new trie;
				c0->merge(*t.c0);
			}
			if (t.c1)
			{
				if (!c1)
					c1 = new trie;
				c1->merge(*t.c1);
			}
			// cout << " - AFTER THAT: \n   ";
			// print();
			// cout << endl;
			// cout << "}END MERGE\n";
		}
		void print() const
		{
			cout << chn << '(';
			if (c0)
			{
				cout << "0: ";
				c0->print();
			}
			if (c0 && c1)
				cout << ", ";
			if (c1)
			{
				cout << "1: ";
				c1->print();
			}
			cout << ')';
		}
		// ~trie()
		// {
		// 	if (c0)
		// 		delete c0;
		// 	if (c1)
		// 		delete c1;
		// }
	} t;
	int main()
	{
		freopen("and.in", "r", stdin);
		freopen("and.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			t.insert(a[i]);
		// t.print();
		// cout << endl;
		cout << t.mx_and(m) << '\n';
		return 0;
	}
}
int main()
{
	return Main::main();
}