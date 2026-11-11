#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
bool vis[N];
void dfs(int cnt,int p){
	if(cnt==m){
		ans=max(ans,p);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true){
			if(cnt==0){
				vis[i]=false;
				dfs(cnt+1,a[i]);
				vis[i]=true;
			}
			else{
				vis[i]=false;
				dfs(cnt+1,p&a[i]);
				vis[i]=true;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=-1e9;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=2147483647;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=-1e9;
		for(int i=1;i<=n;i++){
			int d=2147483647;
			for(int j=1;j<=n;j++){
				if(i!=j){
					d=d&a[j];
				}
			}
			ans=max(ans,d);
		}
		cout<<ans;
		return 0;
	}
	bool flaga=true;
	for(int i=1;i<=n;i++){
		int d=a[i]+1;
		while(d>=2){
			if(d%2!=0){
				flaga=false;
				break;
			}
			d/=2;
		}
		if(flaga=false){
			break;
		}
	}
	if(flaga==true){
		sort(a+1,a+n+1);
		int ans=2147483647;
		for(int i=n;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	bool flagb=true;
	int n0=n;
	while(n0>=2){
		if(n0%2!=0){
			flagb=false;
			break;
		}
		n0/=2;
	}
	if(flagb==true){
		for(int i=1;i<=n;i++){
			if(a[i]!=(i-1)){
				flagb=false;
				break;
			}
		}
	}
	if(flagb==true){
		int ans=2147483647;
		for(int i=n;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	bool flagc=true;
	for(int i=1;i<=n;i++){
		if(a[i]>=4){
			flagc=false;
		}
	}
	if(flagc==true){
		int cnt3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3){
				cnt3++;
			}
		}
		if(cnt3>=m){
			cout<<3;
			return 0;
		}
		int cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==2||a[i]==3){
				cnt2++;
			}
		}
		if(cnt2>=m){
			cout<<2;
			return 0;
		}
		int cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1||a[i]==3){
				cnt1++;
			}
		}
		if(cnt1>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=true;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
