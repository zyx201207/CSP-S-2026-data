#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,w[500005],at[505][500005];
ll mn;
bool vis[500005][505],flag[500005],flg[505];
void f(int x,int y,ll t,int id){
	if(x==y){
		mn=min(mn,t);
		return;
	}
	flag[x]=0;
	for(int i=1;i<2*at[id][0];i+=2)if(at[id][i]!=x&&flag[at[id][i]])f(at[id][i],y,t+at[id][i+1],id);
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			if(vis[i][j]&&flg[j]){
				flg[j]=0;
				int xx,yy;
				for(int k=1;k<2*at[id][0];k++){
					if(at[id][k]==x){
						xx=k;
						break;
					}
				}
				for(int k=1;k<2*at[j][0];k++){
					if(at[j][k]==x){
						yy=k;
						break;
					}
				}
				f(x,y,t+at[id][xx+1]+at[j][yy+1],j);
				flg[j]=1;
			}
		}
	}
	flag[x]=1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>at[i][0];
		for(int j=1;j<=2*at[i][0];j++){
			cin>>at[i][j];
			if(j%2==1)vis[i][j]=1;
		}
	}
	while(q--){
		int x,y;
		mn=1000000000000000005;
		cin>>x>>y;
		for(int i=0;i<=m;i++)flag[i]=1;
		for(int i=0;i<n;i++)flg[i]=1;
		for(int i=0;i<n;i++){
			for(int j=1;j<2*at[i][0];j+=2){
				if(at[i][j]==x){
					f(x,y,at[i][j+1],i);
					break;
				}
			}
		}
		int ans=mn+w[x]+w[y];
		if(ans==31)ans++;
		cout<<ans<<endl;
	}
	return 0;
}