#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,tsum;
int w[200005],k[100005];
int a[500005][201],t[500005][201],x,y;
bool flagA=1;
vector<int> p[15];
int Min=-1;
void f(int nows,int ans){
	if(nows==y){
		if(Min==-1)Min=ans;
		Min=min(Min,ans);
		return;
	}
	for(int i=0;i<=p[nows].size();i++){
		for(int j=1;j<=k[p[nows][i]];j++){
			if(a[p[nows][i]][j]!=0&&a[p[nows][i]][j]!=nows){
				ans+=t[p[nows][i]][j];
				int k=a[p[nows][i]][j];
				a[p[nows][i]][j]=0;
				f(k,ans+t[p[nows][i]][j]);
				a[p[nows][i]][j]=k;
			}
		}		
	}
}
void f2(int nows,int ans){
	if(nows==y){
		Min=min(Min,ans);
		return;
	}
	for(int i=0;i<=p[nows].size();i++){
		for(int j=1;j<=k[p[nows][i]];j++){
			if(a[p[nows][i]][j]!=nows){
				ans+=t[p[nows][i]][j];
				f(a[p[nows][i]][j],ans+t[p[nows][i]][j]);
			}
		}		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)flagA=0;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			p[a[i][j]].push_back(j);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(flagA){
			f2(x,w[x]+w[y]);
		}
		else f(x,w[x]+w[y]);
		cout<<Min<<endl;
	}
	return 0;
}