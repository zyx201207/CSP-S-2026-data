#include<bits/stdc++.h>
using namespace std;
long long mod=100000000;
int c,n,m,d,q,k,w[500005],a[505][20005],t[505][20005],st,en;
bool flag[505][20005]=0
int direct[2]{-1,1};
void def(int st,int en,int d,int r){
	int cnt=0;
	if(st==en){
		mod=min(ans,mod);
		ans=r;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int o=0;o<=1;o++){
			if(t[i][direct[o]+st]!=0&&t[i][direct[o]+st]!=0&&flag[i][direct[o]+st]==0){
				ans+=t[i][st]+t[i][st+direct[o]];
				flag[i][direct[o]+st]==1;
				cnt++;
				return def(st+direct[o],en,d,r);
			}
			if(cnt==n){
				break;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int p=1;p<=k;p++){
			cin>>a[i][p]>>t[i][p];
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>st>>en;
		ans+=w[st]+w[en];
		int r=ans;
		def(st,en,d,r);
		cout<<mod<<endl;
	}
	return 0;	
}