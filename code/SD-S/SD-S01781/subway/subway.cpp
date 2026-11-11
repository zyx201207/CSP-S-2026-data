#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[30010][600];
int b[31000];//kou->ting
int xian[610][30000];
bool kou[30000];
bool lu[600];
long long mzl(int o,int x,int mu,bool h){
	
	long long ans=100000000000;
	kou[o]=1;
	lu[x]=1;
	if(o==mu){
		ans=b[mu];
		return ans;
	}
	if(h==0){
		bool p=0;
		for(int i=1;i<=m;i++)if(lu[i]==0)p=1;
		if(p==0)return ans+1;
		for(int i=1;i<=m;i++){
			if(a[o][i]!=0){
				if(lu[i]==0){
					ans=min(ans,mzl(o,i,mu,1)+a[o][i]);
					lu[i]=0;
				}
			}
		}
	}
	else {
		bool p=0;
		for(int j=1;xian[x][j]>0;j++){
			if(kou[xian[x][j]]==0)p=1;
		}
		if(p==0)return ans+1;
		for(int j=1;xian[x][j]!=0;j++){
			if(kou[xian[x][j]]==0){
				ans=min(ans,mzl(xian[x][j],x,mu,0)+a[xian[x][j]][x]);
				kou[xian[x][j]]=0;
			}
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1,c1;
			cin>>a1>>c1;
			a[a1][i]=c1;
			xian[i][j]=a1;
		}
	}
	for(int i=1;i<=q;i++){
		int qi,di;
		cin>>qi>>di;
		for(int i=1;i<=m;i++)kou[i]=0;
		for(int i=1;i<=n;i++)lu[i]=0;
		cout<<mzl(qi,0,di,0)+b[qi]<<"\n";
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
