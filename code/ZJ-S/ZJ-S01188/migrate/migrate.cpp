#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int a[N];
vector<int> land[N];
map<int,int> ton;
int n,d;
int cnt=0,p;
int ste=1e18;
void dfs(int x,int y,int step){
	if(x>y)return;
	if(x==y){
		ste=min(ste,step);
		if(ste==step)cnt++;
		return;
	}
	for(int i=d;i>=1;i--){
		if(x+i>y)continue;
		if(ton[x+i])dfs(x+i,y,step+1);
	}
}
bool check(int x,int y){
	ste=1e18;
	cnt=0;
	dfs(x,y,0);
	if(cnt==2)return 1;
	else return 0;
}
int solve(int k){
//	cout<<k<<" "<<d<<" "<<n<<endl;
	if(k>=d)return 0;
	int ans=n;
	ans-=((int)(d/k)+1);
	if((a[n]-a[1])%d==0)ans--;
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		for(int i=1;i<=p;i++)land[i].clear();
		ton.clear();
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ton[a[i]]=1;
		}
		int flag=0;
		int tmp=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=tmp)flag=1;
		}
		if(!flag){
			cout<<solve(tmp)<<endl;
			continue;
		}
		p=1;
		for(int i=1;i<=n;i++){
			if(a[i]+d<a[i+1]){
				land[p].push_back(a[i]);
				p++;
				continue;
			}
			land[p].push_back(a[i]);
		}
		for(int i=1;i<=p;i++){
			int sum=0;
			for(int pos1=0;pos1<land[i].size()-1;pos1++){
				for(int pos2=pos1+1;pos2<land[i].size();pos2++){
					if(check(land[i][pos1],land[i][pos2])){
						sum++;
//						cout<<land[i][pos1]<<" "<<land[i][pos2]<<endl;
					}
				}
			}
			ans+=sum;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
code by Ace
*/
