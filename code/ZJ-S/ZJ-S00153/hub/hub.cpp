// Expected bruteforce. But I just can't make it.
// So 0 pt expected.
// Why Google pinyin???
#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <random>
using namespace std;
#define gc getchar

template <typename T>
void read(T &x) {
	x=0; char c;
	T f=1;
	while(!isdigit(c=gc())) if(c=='-') f=-1;
	while(isdigit(c)) x=x*10+c-'0', c=gc();
	x*=f;
	return ;
}

template <typename T>
T read() {
	T x; read(x); return x;
}

int c, t;
int n, k;

struct edge {
	int v;
	int x;
};

edge e[2000005];
int fir[1000005], tot;
//bitset<1000005> v;

void addedge(int u, int v) {
	e[++tot].v=v;
	e[tot].x=fir[u];
	fir[u]=tot;
	return ;
}

mt19937 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main(void) {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	read(c); read(t);
	while(t--) {
		read(n); read(k);
		for(int i = 1; i <= n; ++i) {
			int u, v;
			read(u); read(v);
			addedge(u, v);
			addedge(v, u);
		}
//		for(int i = 1; i <= n; ++i) {
//			for(int j = 1; j <= n; ++j) {
//				if(i==j) continue;
//				v.reset();
//				v[i]=v[j]=1;
//				
//			}
//		}
		uniform_int_distribution<int> rnd(0, n);
		printf("%d\n", rnd(rd));
	}
	
	return 0;
}

/*

I know, I know I've let you down.
I've been a fool to myself--
I thought that I could live for no one else.
But now, through all the hurt and pain, 
it's time for me to respect:
The ones you love means more than anything.

So with sadness in my heart, 
I feel the best thing I could do
is end it all and
leave forever.
What's done is done, it feels so bad?
What once was happy now is sad?
I'll never love again, 
my world is ending...

I wish that I could turn back time.
'Cause now the guilt is all mine, 
(I) can't live without the trust from those you love.
I know, we can't forget the past.
You can't forget love and pride.
Because of that, it's killing me inside.

It all returns to nothing.
It all comes tumbling down tumbling down tumbling down.
It all returns to nothing.
I just keep letting me down letting me down letting me down.

In my heart of hearts, 
I know that I could never love again.
I lost everything--
everything--
everything that matters to me
matters to its world.

I wish that I could turn back time.
'Cause now the guilt is all mine, 
(I) can't live without the trust from those you love.
I know, we can't forget the past.
You can't forget love and pride.
Because of that, it's killing me inside.

It all returns to nothing.
It just keeps tumbling down tumbling down tumbling down.
It all returns to nothing.
I just keep letting me down letting me down letting me down.
It all returns to nothing.
It just keeps tumbling down tumbling down tumbling down.
It all returns to nothing.
I just keep letting me down letting me down letting me down.

Ah ah ah ah.
Tumbling down tumbling down tumbling down.
Ah ah ah ah.
Letting me down letting me down letting me down...
*/
