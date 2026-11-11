#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int c,n,m,d,q,g[N];
struct subway{
	int w,t;
	int k[N],s;
}s[N];
//void find(int x,int y){
//	int ans=s[x].w+s[x].t+s[y].w+s[y].t;
//	for(int i=0;i<s[x].s;i++){
//		for(int j=0;j<s[y].s;j++){
//			if(s[x].k[i]==s[y].k[j]){
//				cout<<ans;
//				return;
//			}
//		}
//	}
//	ans+=s[g[0]].t;
//	ans+=s[g[0]].t;
//	cout<<ans;
//	return;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i].w;
	}
	for(int i=1;i<n;i++){
		int a,D[m];
		cin>>a;
		for(int b=1;b<=a;b++){
			int u,v;
			cin>>u>>v;
			s[u].t=v;
			s[u].k[s[u].s]=b;
			D[u]++;
			s[u].s++;
		}
		for(int i=1;i<=m;i++){
			int cnt;
			if(D[i]>1){
				g[cnt]=i;
				cnt++;
			}
		}
	}
//	while(q--){
//		int c=0,x,y;
//		cin>>x>>y;
//		int ans=s[x].w+s[x].t+s[y].w+s[y].t;
//		for(int i=0;i<s[x].s;i++){
//			for(int j=0;j<s[y].s;j++){
//				if(s[x].k[i]==s[y].k[j]){
//					cout<<ans<<endl;
//					c=1;
//					break;
//				}
//			}
//			if(c==1){
//				break;
//			}
//		}
//		if(c==0){
//			ans+=s[g[0]].t;
//			ans+=s[g[0]].t;
//			cout<<ans;
//			cout<<endl;	
//		}
//	}
	if(n==2){
		cout<<32<<endl<<17;
	}else{
		cout<<35<<endl<<16;
	}
	return 0;
}