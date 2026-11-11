#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;;
int c,t;
int n,k;
int idx,e[N],ne[N],h[N];
bool bj[N];
void add(int x,int y){
	ne[++idx]=h[x],e[idx]=y;h[x]=idx;
}

int edge[1005][1005];


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int x,y;
	while(t--){
		cin>>n>>k;
		
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		for(int i = 1;i<n;i++){
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		
	}
	return 0;
}
