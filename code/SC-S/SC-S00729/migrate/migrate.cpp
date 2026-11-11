#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int INF=2e18;
int a[N],dist[N][N],sum1[N][N],sum[25*N],minn[25*N];
struct node{
	int f,g;
};
map<int,int>mp;
vector<int>b;
void add(int x,int l,int r,int id,int f,int g){
	if(l==r){
		if(minn[x]>f) minn[x]=f,sum[x]=g;
		else if(minn[x]==f) sum[x]+=g;
		return;
	}
	int mid=(l+r)>>1;
	if(id<=mid) add(x*2,l,mid,id,f,g);
	else add(x*2+1,mid+1,r,id,f,g);
	if(minn[x*2]<minn[x*2+1]) minn[x]=minn[x*2],sum[x]=sum[x*2];
	else if(minn[x*2]>minn[x*2+1]) minn[x]=minn[x*2+1],sum[x]=sum[x*2+1];
	else minn[x]=minn[x*2],sum[x]=sum[x*2]+sum[x*2+1]; 
}
node ask(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R) return (node){minn[x],sum[x]};
	int mid=(l+r)>>1;
	node lans,rans,ans;
	lans=rans=ans=(node){INF,0};
	if(L<=mid) lans=ask(x*2,l,mid,L,R);
	if(mid<R) rans=ask(x*2+1,mid+1,r,L,R);
	if(lans.f<rans.f) ans=lans;
	else if(lans.f>rans.f) ans=rans;
	else ans=lans,ans.g+=rans.g;
	return ans; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d,m=0;
		cin>>n>>d;
		b.clear(),mp.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i],m=max(m,a[i]);
			b.push_back(a[i]);
			b.push_back(a[i]-d);
			b.push_back(a[i]+d);
		}
		sort(b.begin(),b.end());
		sort(a+1,a+n+1);
		int pm=1;
		mp[b[0]]=1;
//		cout<<b[0]<<"->"<<1<<"\n";
		for(int i=1;i<b.size();i++){
			if(b[i-1]<b[i]) pm++;
			mp[b[i]]=pm;
//			cout<<b[i]<<"->"<<pm<<"\n";
		}
		for(int i=1;i<=n;i++){
			memset(sum,0,sizeof(sum));
			memset(minn,0x3f3f,sizeof(minn));
			add(1,1,pm,mp[a[i]],0,1);
			for(int j=i+1;j<=n;j++){
				int l=mp[a[j]-d],r=mp[a[j]+d];
				node st=ask(1,1,pm,mp[a[j]-d],mp[a[j]+d]);
				dist[i][j]=st.f+1,sum1[i][j]=st.g;
				add(1,1,pm,mp[a[j]],dist[i][j],sum1[i][j]);
//				cout<<dist[i][j]<<" ";
			}
//			cout<<"\n";
		}
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(dist[i][j]<2e18&&sum1[i][j]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}