#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a1,b1,a2,b2;
}a[500001];
int c,n,m,d,q,ans=INT_MAX,f[500001];
int st,en,s[101],e[101];
int w[501],t[501][1001][2];
int z[501][501];
stack<int>sta;
int dij(int x,int y){
	if(x==y)return t[x][st][2]+t[y][en][2];
	int vis[10001];
	vis[x]=1;
	sta.push(x);
	while(!sta.empty()){
		int top=sta.top();
		sta.pop();
		for(int i=1;i<=n;i++){
			if(z[top][i]==-1)continue;
			if(vis[i]!=0)continue;
			vis[i]=vis[top]+z[top][i];
			sta.push(i);
		}
	}
	return vis[y]+t[x][st][2]+t[y][en][2]-1;
}
int s8(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			z[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
		for(int j=1;j<=w[i];j++){
			cin>>t[i][j][1]>>t[i][j][2];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int x=1;x<=w[i];x++){
				for(int y=1;y<=w[j];y++){
					if(t[i][x][1]==t[j][y][1]){
						z[i][j]=min(z[i][j],t[i][x][2]+t[j][y][2]);
						z[j][i]=min(z[j][i],t[i][x][2]+t[j][y][2]);
					}
				}
			}
		}
	}
	while(q--){
		cin>>st>>en;
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=w[i];j++){
				if(st==t[i][j][1]){
					cnt1++;
					s[cnt1]=i;
				}
				if(en==t[i][j][1]){
					cnt2++;
					e[cnt2]=i;
				}
			}
		}
		for(int i=1;i<=cnt1;i++){
			for(int j=1;j<=cnt2;j++){
				ans=min(ans,dij(s[i],e[j]));
			}
		}
		cout<<ans+f[st]+f[en]<<endl;
	}
}
int s21(){
	int sum=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		for(int j=1;j<=w[i];j++){
			int x;
			cin>>x;
			if(i==1){
				a[x].a1=1;
				cin>>a[x].a2;
			}
			if(i==2){
				a[x].b1=1;
				cin>>a[x].b2;
				if(a[x].a1==1){
					sum=min(sum,a[x].a2+a[x].b2);
				}
			}
		}
	}
	while(q--){
		cin>>st>>en;
		if(a[st].a1==1&&a[en].a1==1){
			ans=min(ans,a[st].a2+a[en].a2);
		}
		if(a[st].b1==1&&a[en].b1==1){
			ans=min(ans,a[st].b2+a[en].b2);
		}
		if(a[st].a1==1&&a[en].b1==1){
			ans=min(ans,a[st].a2+a[en].b2+sum);
		}
		if(a[st].b1==1&&a[en].a1==1){
			ans=min(ans,a[st].b2+a[en].a2+sum);
		}
		cout<<ans+f[st]+f[en]<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>f[i];
	}
	if(n<=2)s21();
	else s8();
	return 0;
}
