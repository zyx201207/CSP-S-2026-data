#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int N=2e6+5;
int n,d;
array<int,N> a;
array<int,N> pre,suf;
signed MainA(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	int b=a[2]-a[1];
	int c=d/b;
	if(c<2){
		cout<<0<<endl;
		return 0;
	}
	cout<<max(0ll,n+1-2*c)<<endl;
	return 0;
}
const int M=3e2+5;
array<array<int,M>,M> dis;
signed Main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	auto f=[&](int x,int y)->bool{
		return a[y]-a[x]<=d;
	};
	// for(int i=1;i<=n;i++)
	// 	for(int j=i+1;j<=n;j++)
	// 		if(f(i,j))	cout<<i<<' '<<j<<endl;
	int ans=0;
	for(int u=1;u<=n;u++){
		int t=1,lst=u;
		for(int v=u+1;v<=n;v++){
			while(v<=n&&f(lst,v))
				dis[u][v]=t,v++;
			if(v>n)	break;
			// cout<<u<<' '<<v<<':'<<t<<endl;
			if(a[v]-a[v-1]>d)
				t=n+1;
			t++,lst=v-1;
			dis[u][v]=t;
		}
	}
	auto CHECK=[&](int u,int v)->bool{
		vector<int> pre(v+1,0);
		pre[u]=1;
		for(int w=u+1;w<=v;w++){
			if(dis[u][w]+dis[w][v]!=dis[u][v])	continue;
			for(int r=w-1;r>=u;r--){
				if(dis[r][w]==1&&dis[u][r]+dis[r][w]==dis[u][w]){
					pre[w]+=pre[r];
					if(pre[w]>2)	return 0;
				}
			}
		}
		// cout<<u<<' '<<v<<' '<<pre[v]<<endl;
		return pre[v]==2;
	};
	for(int len=1;len<n;len++){
		for(int u=1;u+len<=n;u++){
			int v=u+len;
			if(dis[u][v]<=1)
				continue;
			if(dis[u][v]>n)
				continue;
			ans+=CHECK(u,v);
		}
	}
	cout<<ans<<endl;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	clock_t Start=clock();
	int Tc,T;
	cin>>Tc>>T;
	if(Tc==11||Tc==12){
		while(T--)
			MainA();
	}
	else{
		while(T--)
			Main();
	}
	cerr<<(double)(clock()-Start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
/*


aki
*/