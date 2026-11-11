#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+7;
int n,k;
int u[N],v[N];
void solve(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> u[i] >>v[i];
	}
	if(k>=n){
		cout << 0 << '\n';
	}
	else if(k>=n/2){
		cout << 1 << '\n';
	}
	else{
		cout << 2 << '\n';
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		solve();
	}
}

//14:30-15:10 T1 ==100pts
//
//15:10-15:30 thinking T2
//
//15:30 go to WC
//
//15:30-16:10 T2 floyd 1~8 ==32pts
//
//16:10-16:20 think T2 01bfs -> subtaskB 12~19 +=32pts ?
//
//16:20-16:30 T2 floyd 1~8 + bfs 12~15 ==56pts
//
//16:40-16:50 T2 floyd 1~8 + subtaskA 9~11 + bfs 12~15 ==60pts
//
//16:50-17:40 T3 1~6 dp n^3 24pts
//
//17:40 go to WC eat eat
//
//17:40-18:00 T4 canbudong
//
//T1 40min T2 100min T3 50min T4 20min
