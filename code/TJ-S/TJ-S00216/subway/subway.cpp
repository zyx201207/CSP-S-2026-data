#include<bits/stdc++.h>
using namespace std;
short c,d;
int n,m,q;
int w[505];
struct aaa{
	int k;
	int a[3];
	int t[3];
}line[505];
struct bbb{
	int x;
	int y;
}plan[100005];
int ljb[505][505];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);


	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>line[i].k;
		for(int j=1;j<=line[i].k;j++){
			cin>>line[i].a[j]>>line[i].t[j];
		}
		ljb[line[i].a[1]][line[i].a[2]]=line[i].t[1]+line[i].t[2];
		ljb[line[i].a[2]][line[i].a[1]]=line[i].t[1]+line[i].t[2];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(ljb[i][j]!=0){
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					if(ljb[i][k]!=0&&ljb[j][k]!=0){
						ljb[i][j]=min(ljb[i][j],ljb[i][k]+ljb[j][k]);
						ljb[j][i]=min(ljb[j][i],ljb[i][k]+ljb[j][k]);
					}
				}
			}else{
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					if(ljb[i][k]!=0&&ljb[j][k]!=0){
						ljb[i][j]=ljb[i][k]+ljb[j][k];
						ljb[j][i]=ljb[i][k]+ljb[j][k];
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>plan[i].x>>plan[i].y;
		ans+=w[plan[i].x];
		ans+=w[plan[i].y];
		ans+=ljb[plan[i].x][plan[i].y];
		cout<<ans<<endl;
	}
	
	
	return 0;
}
