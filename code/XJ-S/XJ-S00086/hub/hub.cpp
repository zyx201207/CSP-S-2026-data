#include<bits/stdc++.h>
using namespace std;
const int N=10e5+10;
struct edge{
	int u,v;
}e[N];
int find(int x){
	if(fa[x]!=x);
	
}
long long c,t,n,k,ans,cnt;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		t--;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>e[i].u>>e[i].v;
		}
		if(n==2){
			cout<<1<<endl<<2;
		} 
	}
	return 0;
}
