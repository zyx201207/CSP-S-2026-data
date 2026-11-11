#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,id,l,l1,l2;
ll f[510][510],tt[500010],ans,x,y;
struct sss{
	ll num,len;
}t1,t2;
vector<sss> a[500010];
ll read(){
	char c=getchar();
	ll s=0;
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') s=(s<<3)+(s<<1)+c-'0',c=getchar();
	return s;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) tt[i]=read();
	for(int i=1;i<=n;i++){
		cin>>l;
		t1.num=i;
		for(int j=1;j<=l;j++){
			x=read(),y=read();
			t1.len=y;
			a[x].push_back(t1);
		}
	}
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		l=a[i].size();
		for(int j=0;j<l;j++)
		for(int k=j+1;k<l;k++){
			t1=a[i][j],t2=a[i][k];
			f[t1.num][t2.num]=f[t2.num][t1.num]=min(f[t1.num][t2.num],t1.len+t2.len);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		x=read(),y=read();
		ans=1e18;
		l1=a[x].size();
		l2=a[y].size();
		for(int i=0;i<l1;i++)
		for(int j=0;j<l2;j++){
			t1=a[x][i];
			t2=a[y][j];
			ans=min(ans,t1.len+t2.len+f[t1.num][t2.num]);
		}
		printf("%lld\n",ans+tt[x]+tt[y]);
	}
	return 0;
}
