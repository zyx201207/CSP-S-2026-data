#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;

int n,m;
int ans;
int a[N];
int vis[N];

int bere(int x,int y){
	int ans=0;
	int base=1;
	while(y>0){
		ans+=((x%2)^1)*base;
		base*=2;
		x>>=1;
		y>>=1;
	}
	return ans;
}

void dfs(int deep=1,int s=1){
	if(deep>m){
		int an=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			if(an==-1) an=a[i];
			else{
				an&=a[i];
			}
		}
		ans=max(ans,an);
		return ;
	}
	for(int i=s;i<=n;i++){
		vis[i]=1;
		dfs(deep+1,i+1);
		vis[i]=0;
	}
	return ;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20&&m<=n){//1~5
		ans=-4e18;
		dfs();
		cout<<ans;
	}
	else if(n<=2000&&m==1){//6
		ans=-4e18;
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(n<=2000&&m==n){//7
		ans=a[1];
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(n<=2000&&m==2){//8~10
		ans=-4e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n<=N&&m==n-1){//11,12
		ans=-4e18;
		int an=a[1];
		for(int i=1;i<=n;i++) an&=a[i];
		for(int i=1;i<=n;i++) ans=max(an|bere(a[i],an),ans);
		cout<<ans;
	}
	else if(n<=N&&m<=n){//13
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++){
			if(a[i]>=4){
				f2=0;
			}
			if(a[i]!=i-1){
				f1=0;
			}
		}
		if(f1){//14,15
			ans=a[n];
			for(int i=n;i>n-m;i--) ans&=a[i];
			cout<<ans;	
		}
		else if(f2){//16,17
			int cnt1=0,cnt2=0,cnt3=0;
			for(int i=1;i<=n;i++){
				cnt1+=(a[i]==1);
				cnt2+=(a[i]==2);
				cnt3+=(a[i]==3);
			}
			if(cnt3>=m) cout<<3;
			else{
				if(cnt3+cnt2>=m) cout<<2;
				else{
					if(cnt3+cnt1>=m) cout<<1;
					else cout<<0;
				}
			}
		}
		else{
			sort(a+1,a+1+n,greater<int>());
			cout<<a[m];	
		}
	}
	else{
		dfs();
		cout<<ans;
	}	
	return 0;
}
