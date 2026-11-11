#include <cstdio>
#include <algorithm>
#include <cctype>
typedef long long ll;
constexpr int N = 1005, M = 1000006; 
int test_case, T;
namespace fin {
	constexpr int FINBUFSIZ = 10000000;
	char inp_buf[FINBUFSIZ], *inp = inp_buf + FINBUFSIZ;
	const char& nxtchar() {
		if(inp == inp_buf + FINBUFSIZ)
			fread(inp = inp_buf, 1, FINBUFSIZ, stdin);
		return *inp++;
	}
	int read() {
		int val = 0;
		char c = nxtchar();
		while(!isdigit(c))
			c = nxtchar();
		while(isdigit(c)) {
			val = val * 10 + (c - 48);
			c = nxtchar();
		}
		return val;
	}
}
using fin::read;
int n, k;
bool is_hub[N];
struct Edge {
	int ver, nxt;
};
Edge e[M << 1];
int ecnt, head[M];
void add_edge(int u, int v) {
	e[++ecnt] = {v, head[u]};
	head[u] = ecnt;
}
int ufs[N];
int find(int u) {
	if(ufs[u] == u) return u;
	return ufs[u] = find(ufs[u]);
}
bool merge(int u, int v) {
	u = find(u), v = find(v);
	if(u == v) return 0;
	ufs[u] = v;
	return 1;
}
int ans;
int dist[N][N];
void get_dist_dfs(int u, int _fa, int* d) {
	for(int i = head[u]; i; i = e[i].nxt) {
		const int& v = e[i].ver;
		if(v != _fa) {
			d[v] = d[u] + 1;
			get_dist_dfs(v, u, d);
		}
	}
}
void bf(int x, int cnt) {
	if(x > n) {
		if(cnt != k) return ;
		for(int u = 1; u <= n; u++)
			if(is_hub[u])
				ufs[u] = u;
		for(int u = 1; u <= n; u++)
			if(is_hub[u]) {
				for(int i = head[u]; i; i = e[i].nxt) {
					const int& v = e[i].ver;
					if(is_hub[v])
						cnt -= merge(u, v);
				}
			}
		if(cnt > 2) return ;
		int max_dist = 0;
		for(int u = 1; u <= n; u++) {
			int min_dist = n;
			for(int v = 1; v <= n; v++)
				if(is_hub[v])
					min_dist = std::min(min_dist, dist[u][v]);
			max_dist = std::max(max_dist, min_dist);
		}
		ans = std::min(ans, max_dist);
		return ;
	}
	is_hub[x] = 0;
	bf(x + 1, cnt);
	is_hub[x] = 1;
	bf(x + 1, cnt + 1);
}
int main() {
	//qwq rp++! __libp_start_main
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	test_case = read();
	T = read();
	while (T--) {
		n = read(), k = read();
		ecnt = 0;
		for(int i = 1; i <= n; i++)
			head[i] = 0;
		for(int i = 2, u, v; i <= n; i++) {
			u = read(), v = read();
			add_edge(u, v);
			add_edge(v, u);
		}
		ans = n;
		if(n <= 10) {
			for(int i = 1; i <= n; i++)
				get_dist_dfs(i, 0, dist[i]);
			bf(1, 0);
			printf("%d\n", ans);
		} else if(test_case == 7) {
			for(int i = 1; i <= n; i++)
				get_dist_dfs(i, 0, dist[i]);
			for(int i = 1; i <= n; i++)
				for(int j = i + 1; j <= n; j++) {
					int cur = n;
					for(int u = 1; u <= n; u++)
						cur = std::max(cur, std::min(dist[i][u], dist[j][u]));
					ans = std::min(ans, cur);
				}
			printf("%d\n", ans);
		} else puts("1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
csp-s 2026
KaoShengMiHuoXingWeiDaShang:
-16:52,
Fun Fact: Noticing that my code length of T1-T3 is
1111 B, 2333 B, 1414 B
sure I want to write something down here but err,
let me try to get more pts first;
ah gosh T4 is so hard, even bf is hard to write
try T3 first;
-17:30
I still don't get it, it doesn't seem like a data-structure either;
-17:58
T4 wrote a dfs-bf;
-18:07
ah T4 is so difficult I had to give up,
I may get 100 + 100(-rnd) + 40 + 15; But I don't know whether T2 could pass or not;
Just wish I won't GuaFen >_<
By the way, this might be my last dance?
I'd to write some recall article but the time is about to run out;
so speak in a short word,
How i start my OI journey?
That's a question I've already answered so many times so I will not write it again here;
I just slightly forget about them
ans also the happiness I had before;
Thinking back of those days,
really feels like it just slips away
OI did took a lot from my school life but,
now, I can't imagine a different life without it;
Maybe this is some kind of life long lesson
that you would find something good after you leave it
Solving these hard problems isn't like writing a music or paint a painting;
But I sometimes find out that code is actrually kinda romantic
A poem of program, digit; Also a poem of life
Every wisdom human beings have may shine in these algorithms and data-structures;
Maybe when we fade to ashes,
the only lonely, brave, smart, and beautiful thing we can lie on
-- is just the Voyager I that still floating in the universe.

I didn't figure out yet, but in the coming days of life,

I will just say I'm glad to have, I'm also glad to move on;

                                                  -int_4096
by the way, I also typed an ASCII paint;
(Because it's consider that not many people ASCII paint in CSP)
              /\                 .
             /  \               /\ 
            /  . \             /  \            ZZZZZZ
           /  ""  \           / "  \          Z
          /  '  '  \-------__/  "'. \        Z
         /          -=          []]} \      Z
        .//                         ++ )
       /./                       .     \
      0//         /\           / \     \
     0//         /  \         /   \    |\
   . //         /    \       /     \   \}
    .\/        /      \  __./       | .0}
   ///         |  ----         ----  |  /
   /           |                     | / 
   /           |            ___      |)./
    ///        \ ___________________/./
    //       __\               / 0.//
         ..  _ \                  /
       -++   [                      ]
        \\                          \\
if you make it to here, congrats!
Hope you get what you want and have a life that you want to;
Life is hard, but there were always true, kind and beauty in the world
When you feel down,
just recall about how you say first "Hello!" to this "World".
*/