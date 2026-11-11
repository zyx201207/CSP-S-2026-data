#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define Mp make_pair
#define fir first
#define sec second
#define lowbit(x) (x & -x)

using namespace std ;

inline int read() {int x = 0 ; bool w = 0 ; char c = getchar() ;  while(!isdigit(c)) {w |= (c == '-') ,c = getchar();} while(isdigit(c)) {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar() ;  } return w ? -x : x;}
inline void write(int x){if(x < 0) putchar('-') ,x = -x;if(x > 9) write(x / 10);putchar(x % 10 | 48);}
inline void writesp(int x) { write(x) ,putchar(' ') ;}
inline void writeln(int x) { write(x) ,putchar('\n') ;}

const int N = 5e5 + 10;
int n ,m ,a[N] ,lst[N] ,pos[N] ,indeg[N] ,ans[N];
//int arr[N] ,id[N] ,sum[N];
//vector <int> vec[N] ,vc ;
vector <int> edge[N];
queue <int> q;

//inline int calc(int arr[] ,int cnt ,int c) {
//	up(i ,1 ,cnt) id[arr[i]] = 0 ; 
//	up(i ,1 ,cnt) {
//		if(!id[arr[i]]) id[arr[i]] = i ; 
//		else {
//			up(j ,id[arr[i]] ,i - 1) id[arr[j]] = 0 ; 
//			id[arr[i]] = i ; 
//		}
//	}
//	
//	up(i ,1 ,cnt) if(id[arr[i]]) {
//		ans[arr[i]] += c ,id[arr[i]] = 0;
////		vec[i].push_back(n - cnt + 1);
//	}
//}
//inline void Sub() {
//	int p = 1;
//	up(i ,1 ,n){
//		while(a[p + 1] == a[i] && p < n) ++ p ; 
//		ans[a[i]] = p ; 
//		i = p ;
//	}
//	up(i ,1 ,m) writesp(ans[i]) ; puts("") ;
//}
//inline void Sub1() {
//	if(m == 1) {
//		writeln(n) ; return ; 
//	}
//	up(i ,1 ,n) vec[a[i]].push_back(i);
//	up(i ,1 ,m) {
//		int len = vec[i].size();
//		int pos = vec[i][len - 1];
//		if(pos == n) ans[i] = n ;
//		else ans[i] = sum[i];
//	} up(i ,1 ,m) writesp(ans[i]);
//}
//inline void Sub2() {
//	vc.push_back(0);
//	up(i ,1 ,n - 1) if(a[i] != a[i + 1]) vc.push_back(i);
//	vc.push_back(n);
//	int len = vc.size();
////	for(int v : vc) writesp(v) ; puts("") ;
//	up(i ,1 ,len - 1) {
//		int cnt = 0 ;
//		up(j ,i ,len - 1) {
//			if(vc[j] <= n) arr[++ cnt] = a[vc[j]] ;
//		} //up(j ,1 ,cnt) cout << arr[j] << ' ' ;
//	//	cout << endl; 
//		calc(arr ,cnt ,vc[i] - vc[i - 1]);
//	} up(i ,1 ,m) writesp(ans[i]) ; puts("") ;
//}
//inline void Sub3(){
//	up(_ ,1 ,n) {
//		int cnt = 0 ;
//		up(j ,_ ,n) arr[++ cnt] = a[j];
//		calc(arr ,cnt ,1);
//	}
//	
//	up(i ,1 ,m) {
////		cout << "* " << i << " : "; 
////		writeln(ans[i]) ;
////		for(int j : vec[i]) writesp(j) ,writeln(a[j]); puts("") ;
//		writesp(ans[i]) ;
//	}
//}
//inline void Sub4() {
//	up(i ,1 ,m) {
//		int cnt = 0 ;
//		up(j ,lst[i] ,n) arr[++ cnt] = a[j];
//		calc(arr ,cnt ,pos[i]) ;
//	} up(i ,1 ,m) writesp(ans[i]) ; puts("") ;
//}
inline void topo() {
	up(i ,1 ,n) if(!indeg[i]) q.push(i) ;
	while(!q.empty()) {
		int u = q.front() ; q.pop();
		for(int v : edge[u]) {
			ans[v] += ans[u] ,-- indeg[v];
			if(!indeg[v]) q.push(v);
		}
	}
}
namespace lolcrying {

	signed main() {
		
		n = read() ,m = read();
		up(i ,1 ,n) a[i] = read() ,/*++ sum[a[i]] ,*/lst[a[i]] = i ,++ pos[a[i]];
		
//		bool flag = 1 ,flag1 = 1 ; int s = 0 ; 
//		up(i ,1 ,n - 1) flag &= (a[i] <= a[i + 1]) ,flag1 &= (a[i] <= 2) ,s += (a[i] != a[i + 1]);
//		flag1 &= (a[n] <= 2);
//		
//		if(flag) {
//			Sub();
//			return 0 ;
//		}
//		if(flag1) {
//			Sub1();
//			return 0 ;
//		}
//		
//		if(s <= 5000) {
//			Sub2();
//			return 0 ;
//		}
//		
//		if(n <= 5000) {
//			Sub3() ;
//			return 0 ;
//		}
//		
//		if(m <= 3000) {
//			Sub4();
//			return 0 ;
//		}
		
		up(i ,1 ,m) {
			if(lst[i] != n) edge[i].push_back(a[lst[i] + 1]) ,indeg[a[lst[i] + 1]] ++ ; 
			ans[i] = pos[i];
		} 
		
		topo();
		up(i ,1 ,m) writesp(ans[i]) ; puts("") ;
//		int su = 0 ;
//		up(i ,1 ,m) {
//			su += n - lst[i] + 1; 
//		} writeln(su);
		
		return 0 ;
	}
} signed main() {
	
	freopen("card.in" ,"r" ,stdin);
	freopen("card.out" ,"w" ,stdout);
	
	int T = 1;
//	int T = read() ; 
	while(T --) lolcrying :: main();
	return 0 ;
	
}

