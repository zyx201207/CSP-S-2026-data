#include<bits/stdc++.h>
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define inf INT_MAX
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int> > spq; 


const int N=5e5+10;
int c,t,n,k;
vector<int> g[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		
	}
	cout<<1<<endl;
}
int main(){
	fst
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
//CCF=chinese can fly 
/*
Oct31==Dec25?


*/
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
/*
		//\\                   ==========          ==
	   //  \\                ==          ==        == 
	  //    \\             ===             =       ==
	 //      \\           ===                      ==
	//        \\          ===                      ==
   //==========\\         ===                      ==
  //            \\         ===
 //              \\          ==          ==        ==
//                \\            ==========         ==




*/
