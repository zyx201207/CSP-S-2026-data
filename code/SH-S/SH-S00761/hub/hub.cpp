//1
#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,l,md,r,cnt;
vector<vector<int>> v;
bool f[2000200];
void find(int u,int d){
	if(d>md)return;
	for(auto &x:v[u]){
		if(!f[x]){
			f[x]=1;
			find(x,d+1);
		}
	}
	cnt++;
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		v.assign(n+5,vector<int>());
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		l=1,r=n;
		bool g=0;
		while(l<=r){
			md=(l+r)/2;
			for(int i=0;i<n;i++){
				memset(f,0,sizeof(f));
				find(i,k);
				if(cnt==n){
					g=1;
					break;
				}
			}
			if(g){
				l=md+1;
			}
			else{
				r=md-1;
			}
		}
		//cout<<r<<endl;
	}
} 
