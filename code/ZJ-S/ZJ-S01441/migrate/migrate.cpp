#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,M=5010;
int x[N],f[N],num[N],b[N];
void solve(){
	int n,d,cnt,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		while(x[f[i]+1]-x[i]<=d&&f[i]+1<=n)f[i]++;
	}
	for(int i=2;i<=n;i++){
		if(x[i]-x[i-2]<=d)num[i]=f[i-1]-f[i-2];
	}
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<f[i]<<" "<<ans<<"\n";
		cnt=1;
		b[cnt]=i;
		while(1){
			if(f[b[cnt]]==b[cnt])break;
			cnt++;
			b[cnt]=f[b[cnt-1]];
			if(b[cnt]==n)break;
		}
		//cout<<i<<" "<<cnt<<"\n";
		bool flag=0;
		for(int j=2;j<cnt;j++){
			//cout<<b[j]<<"\n";
			if(b[j]-b[j-1]>1&&flag==0){
				ans+=f[b[j]-1]-f[b[j]-2];
				if(f[b[j]-1]==b[j+1]){
					flag=1;
					if(f[b[j]-1]-f[b[j]-2]==0)break;
				}
			}else if(flag==1){
				if(f[b[j]-1]==b[j+1])break;
				ans+=b[j+1]-b[j];
				//cout<<i<<" "<<b[j]<<" "<<b[j+1]<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
int nm[M],dis[M];
queue<int>q;
bool vis[M];
void solve2(){
	vector<int>v[M];
	int n,d,cnt,ans=0,p;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		while(x[f[i]+1]-x[i]<=d&&f[i]+1<=n)f[i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=f[i];j++){
			v[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)vis[j]=nm[j]=0;
		cnt=1;
		b[cnt]=i;
		while(1){
			if(f[b[cnt]]==b[cnt])break;
			cnt++;
			b[cnt]=f[b[cnt-1]];
			if(b[cnt]==n)break;
		}
		for(int j=1;j<cnt;j++){
			for(int k=b[j]+1;k<=b[j+1];k++)dis[k]=j;
		}
		dis[i]=0;
		nm[i]=1;
		q.push(i);
		while(!q.empty()){
			p=q.front();
			q.pop();
			for(auto son:v[p]){
				if(dis[son]==dis[p]+1){
					nm[son]+=nm[p];
					if(!vis[son]){
						vis[son]=1;
						q.push(son);
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(nm[j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)v[i].clear();
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>10)while(t--)solve();
	else while(t--)solve2();
	return 0;
}
//0 1
//7 666666666666666663
//-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989