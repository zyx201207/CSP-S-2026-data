#include<bits/stdc++.h>
using namespace std;
const long long oo=1e18;
int c,n,m,d,q;
int w[500005],a[505][1005],k[505],t[505][1005];
long long Ans=oo;
void dfsA(int x,int end,long long spendtimes,int line){
	if(x==end){
		Ans=min(Ans,spendtimes);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				if(i!=line){
					int tmp;
					for(int ll=1;ll<=k[line];ll++)if(a[line][ll]==x)tmp=ll;
					if(a[i][j+1]==end){
						dfsA(a[i][j+1],end,spendtimes+t[line][tmp]+t[i][j]+t[i][j+1],i);
					}
					else {
						if(line!=0)dfsA(a[i][j+1],end,spendtimes+t[line][tmp]+t[i][j],i);
						else dfsA(a[i][j+1],end,spendtimes+t[i][j],i);
					}
				}
				else{
					if(a[i][j+1]==end){
						dfsA(a[i][j+1],end,spendtimes+t[i][j+1],line);
					}
					else dfsA(a[i][j+1],end,spendtimes,line);
				}
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		Ans=oo;
		long long x,y;
		cin>>x>>y;
		dfsA(x,y,w[x]+w[y],0);
		cout<<Ans<<"\n";
	}
	return 0;
} 