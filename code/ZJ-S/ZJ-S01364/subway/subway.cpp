#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,j,jj,q,i,t,t1,baoa,baot,t2,l,xj,yj,r,s[510][510],at[500010],st[500010],w[5000010],b[500010],xx[510],yy[510];
long long mi,dp[510][510];
int f[500010][502];
struct node{
	int a;
	short int t;
};
node bao;
vector<node> a[510];
bool cmp(node t,node w){
	return t.a<w.a;
}
void sc(int x){
	int i,t,w,xh,ih;
	t=w=1;
	at[t]=x;
	st[t]=0;
	while(t<=w){
		for(i=1;i<=n;i++){
//			xh=x;ih=i;
//			if(xh<ih)swap(xh)
			if(s[at[t]][i]!=2e9&&i!=x)
				if(s[at[t]][i]+st[t]<dp[x][i]){
					dp[x][i]=s[at[t]][i]+st[t];
					dp[i][x]=s[at[t]][i]+st[t];
					st[++w]=dp[x][i];
					at[w]=i;
				}
			}
		t++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
//	q=1;
	for(i=1;i<=m;i++)
		cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>b[i];
		a[i].push_back(bao);
		for(j=1;j<=b[i];j++){
			cin>>baoa>>baot;
			bao.a=baoa;bao.t=baot;
			a[i].push_back(bao);
			f[a[i][j].a][i]=baot;
		}
		sort(a[i].begin()+1,a[i].begin()+1+b[i],cmp);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			s[i][j]=2e9;
	for(i=1;i<=n;i++)
		s[i][i]=0;
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j){
			if(i==j)continue;
			t=1;t2=1;
			while(t<=b[i]&&t2<=b[j]){
				while(a[j][t2].a<a[i][t].a&&t2<=b[j])
					t2++;
				if(t2==b[j]+1)
					break;
				if(a[j][t2].a==a[i][t].a)
					s[j][i]=s[i][j]=min(s[i][j],a[j][t2].t+a[i][t].t);
				if(t==b[i])
					break;
				t++;
			}
		}
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)
			s[i][j]=s[j][i];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)dp[i][j]=dp[j][i]=2e9;
		dp[i][i]=0;
		sc(i);
	}
	for(i=1;i<=q;++i){
		cin>>l>>r;
		t1=t2=0;
		mi=2e9;
		for(j=1;j<=n;++j){
			if(f[l][j])
				xx[++t1]=j;
			if(f[r][j])
				yy[++t2]=j;
		}
		for(j=1;j<=t1;++j)
			for(jj=1;jj<=t2;++jj){
				xj=xx[j];yj=yy[jj];
//				if(xj>yj)
//					swap(xj,yj);
				if(dp[xj][yj]!=2e9)
					mi=min(mi,dp[xj][yj]+f[l][xj]+f[r][yj]);
				}
		cout<<mi+w[l]+w[r]<<endl;
	}
}
