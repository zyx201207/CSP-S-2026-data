 #include<bits/stdc++.h>
 using namespace std;
 #define For(a,b,c) for(int a=b;a<=c;a++)
 #define Rof(a,b,c) for(int a=b;a>=c;a--)
 #define int long long
 
 const int N=2e6+5;
 
 int c,T,n,d;
 int a[N],cnt[N],dis[N];
 
 void dfs(int x,int dd){
 	if(dis[x]>dd)dis[x]=dd,cnt[x]=1;
 	else if(dis[x]==dd)cnt[x]++;
 	else return ;
 	if(x==n)return ;
 	int v=upper_bound(a+1,a+n+1,a[x]+d)-a-1;
// 	cout<<x<<' '<<v<<'\n';
 	Rof(i,v,x+1){
 		dfs(i,dd+1);
	 }
 }
 
 signed main(){
 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	For(i,1,T){
		cin>>n>>d;
		For(j,1,n)cin>>a[j];
		int ans=0;
		For(j,1,n-2){
//			cout<<"S: "<<j<<'\n';
			For(tt,j,n){
				cnt[tt]=0;
				dis[tt]=0x3f3f3f3f3f3f3f3f;
			}
			dfs(j,0);
			For(tt,j+2,n){
//				cout<<cnt[tt]<<' ';
				if(cnt[tt]==2)ans++;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0; 
 }
