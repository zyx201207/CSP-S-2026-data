#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,t;
}at[500005];
long long w[500005],s[10005][10005],c,n,m,d,q,k,x,y;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(s,0x3f3f,sizeof(s));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>at[j].a>>at[j].t;
		}
		for(int j=1;j<=k;j++){
			for(int q=j+1;q<=k;q++){
				s[at[j].a][at[q].a]=at[j].t+at[q].t;
				s[at[q].a][at[j].a]=at[j].t+at[q].t;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j && j!=k && i!=k){
					s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
				}
			}
		}
	}
	long long ans;
	while(q--){
		cin>>x>>y;
		ans=s[x][y]+w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
