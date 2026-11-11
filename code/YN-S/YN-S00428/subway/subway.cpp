#include <bits/stdc++.h>
using namespace std;


//class Grapth{
//	public:
//		vector<Node> nodes;
//
//};


class Edge {
	public:
		int w;
		int to;
		Edge(int w, int to) {
			this->w = w;
			this->to = to;
		}
};

class Node {
	public:
		int t;
		int id;
		int t1;
		int is;
		vector<Edge> edges;
		Node(int t, int id) {
			this->id = id;
			this->t = t;
			this->is = false;
		}
};

//
//void dfs(vector<Node> &nodes, int s, int e, int id1) {
//	cout << id1 << endl;
//	nodes[id1 - 1].is = true;
////	ans +=
//
//	for (int i = 0; i < nodes[id1 - 1].edges.size(); i++) {
//
//		if (!nodes[nodes[id1 - 1].edges[i].to - 1].is) {
////			cout << nodes[nodes[id1 - 1].edges[i].to - 1].id << "==" << endl;
//			dfs(nodes, s, e, nodes[id1 - 1].edges[i].to);
////			cout << nodes[nodes[id1 - 1].edges[i].to - 1].id << "==" << endl;
//		}
//
//	}
//}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int a1, line, st, b1, q1;
	vector<Node> nodes;
	cin >> a1 >> line >> st >> b1 >> q1;

	for (int i = 0; i < st; i++) {

		int a;
		cin >> a;
		nodes.push_back(Node(a, i + 1));
	}

	for (int i = 0; i < line; i++) {

		int a;
		cin >> a;
		vector<int> v1;

		for (int j = 0; j < a; j++) {

			int b, c;
			cin >> b >> c;
			nodes[b - 1].t1 = c;
			v1.push_back(b);
		}

		for (int i = 0; i < v1.size(); i++) {

			for (int j = 0; j < v1.size(); j++) {

				if (i != j) {
					nodes[v1[i] - 1].edges.push_back(Edge(nodes[v1[i] - 1].t1 + nodes[v1[j] - 1].t1, v1[j]));
				}

			}
		}
	}

//	cout << nodes[3].id << " " << nodes[3].t << endl;
//
//	for (int i = 0; i < nodes[3].edges.size(); i++) {
//
//		cout << nodes[3].edges[i].w << endl;
//	}

	for (int i = 0; i < q1; i++) {

		int s, e;
		cin >> s >> e;
		int ans = nodes[s - 1].t + nodes[e - 1].t;

		queue<Node> q;
		q.push(nodes[s - 1]);
		bool f = false;

		while (!q.empty() && !f) {
			Node n = q.front();
			nodes[n.id - 1].is = true;
			q.pop();
			//		cout << n.id << endl;

			for (int i = 0; i < n.edges.size(); i++) {

				int a = n.edges[i].to;



				if (!nodes[a - 1].is) {
					q.push(nodes[a - 1]);
					ans += n.edges[i].w;
					nodes[a - 1].is = true;
				}

				if (nodes[a - 1].id = e) {
					//				cout << ans << endl;
					f = true;
					break;
				}

			}
		}

//	dfs(nodes, s, e, s);

		cout << ans;
		ans = 0;

	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
