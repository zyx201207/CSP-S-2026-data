#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005],all[500005];
struct line{
	int sta_id,sta_t;
}sta[505][500005];
int x1[100005],x2[100005],ans[100005];
int time(int st,int ed){
	int t=a[st]+a[ed];
	
	return t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>all[i];
		for(int j=1;j<=all[i];j++) cin>>sta[i][j].sta_id>>sta[i][j].sta_t;
	}
	for(int i=1;i<=q;i++){
		cin>>x1[i]>>x2[i];
		ans[i]=time(x1[i],x2[i]);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}