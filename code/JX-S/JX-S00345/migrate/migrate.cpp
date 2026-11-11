#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e6+10,MAXT=1e4,mod=998244353,inf=1e12;
int n,d;
int a[N];
int cnt,minn;
bool f=0;
int times=0;
void dfs(int now,int step,int x){
	times++;
	if(times>MAXT)return ;
	if(now==x){
		f=1;
		// cerr<<step<<" "<<cnt<<endl;
		if(step<minn){
			cnt=1;
			minn=step;
		}
		else if(step==minn)cnt++;
	}
	for(int i=now+1;i<=x;i++){
		if(a[i]-a[now]>d)break;
		dfs(i,step+1,x);
		// puts("yes");
	}
}
bool check(int x,int y){
	if(y-x+1<=3)return 0;
	minn=inf;
	f=0;
	dfs(x,0,y);
	if(times>MAXT)return 0;
	// cerr<<cnt<<endl;
	// if(cnt==2&&f)cerr<<x<<" "<<y<<endl;
	return cnt==2&&f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	// srand(time(0));
	cin.tie(0);
	cout.tie(0);
	int c,T,ans=0;
	// int zero=0;
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i+3<=n;i++){
			for(int j=i+3;j<=n;j++){
				ans+=check(i,j);
				if(times>MAXT)break;
			}
			if(times>MAXT)break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
17:08
dfs
O(n^4)
8pts
*/