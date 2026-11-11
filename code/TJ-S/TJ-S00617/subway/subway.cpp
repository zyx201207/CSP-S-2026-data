#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
struct node{
	int u,v;
}a1[20],a2[20],a3[20];
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k;
	if(n==1){
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>a1[i].u>>a1[i].v;
		}
		while(q--){
			int ans=0,x,y;
			cin>>x>>y;
			ans+=w[x]+w[y];
			ans+=a1[x].v+a1[y].v;
			cout<<ans<<'\n';
		}
	}
	if(n==2){
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>a1[i].u>>a1[i].v;
		}
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>a2[i].u>>a2[i].v;
		}
		while(q--){
			int ans=0,x,y;
			cin>>x>>y;
			ans+=w[x]+w[y];
			ans+=a1[x].v+a1[y].v;
			
			int l=a1[x].u,r=a1[y].u;
			if(a1[x].u>a1[y].u){
				r=a1[x].u;
				l=a1[y].u;
			}
			for(int i=l;i<=r;i++){
				ans+=a1[i].v;
			}
			
			
			cout<<ans<<'\n';
		}
	}
	return 0;
}
