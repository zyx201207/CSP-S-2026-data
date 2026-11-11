#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	}
	sort(a+1,a+n+1);
	int f=0,ca=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=ca){
			f=1;
			break;
		}
	}
	if(f==0){
		int y=0,kl=ca;
		for(int i=1;i<=n;i++){
			y=y+kl;
			if(y>m){
				cout<<i<<endl;
				return 0;
			}
			kl+=ca;
		}
		cout<<n<<endl;
		return 0;
	}
	int ans=0;
	a[n+1]=1e15;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		int p=0,cnt=0;
		for(int j=i;j>=1;j--){
			p+=a[i]-a[j];
			if(p<=m){
				cnt++;
			} else {
				break;
			}
		} 
		ans=max(ans,cnt);
	}
	
	cout<<ans<<endl;
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
map<int,int>mp;
int n,m,a[N],b[N],k,p=0,ans=0;
void dfs(int id,int t,int s){
	if(id>n){
		ans=max(ans,s);
		return;
	}
	if(t+k-a[id]<=m&&a[id]<=k) dfs(id+1,t+k-a[id],s+1);
	dfs(id+1,t,s);
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int f=0,ca=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=ca){
			f=1;
			break;
		}
	}
	if(f==0){
		int y=0,kl=ca;
		for(int i=1;i<n;i++){
			y=y+kl;
			if(y>m){
				cout<<i<<endl;
				return 0;
			}
			kl+=ca;
		}
		cout<<n<<endl;
		return 0;
	}
	a[0]=-1e15;
	int cnt=0;
	for(int i=1;i<=n;i++){
		k=a[i];
		ans=0;
		if(a[i-1]!=a[i]){
			dfs(1,0,0);
			//cout<<k<<" "<<ans<<endl;
			cnt=max(cnt,ans);
		}
	}
	cout<<cnt<<endl;
	return 0;
}*/
