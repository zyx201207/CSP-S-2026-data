#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int maxn=200005;
int a[maxn];
int b[maxn];
int n,m;
int ans;
bool checkA(){
	for(int i=1;i<=n;i++){
		int lg=log2(a[i]+1);
		if((1<<lg)!=a[i]+1) return false;
	}
	return true;
}
void dfs(int x,int has,int sum){
	if(sum<ans) return;
	if(has>m||has+(n-x+1)<m) return;
	if(x>n&&has==m){
		if(sum>ans) ans=sum;
		return;
	}
	dfs(x+1,has,sum);
	dfs(x+1,has+1,sum&a[x]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) if(a[i]>ans) ans=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=5000){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) if((a[i]&a[j])>ans) ans=a[i]&a[j];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(checkA()){
		ans=a[n-m+1];
		cout<<ans;
		return 0;
	}
	if(a[n]<=4){
		int cnt=0;
		for(int i=n;i>=1;i--){
			if(a[i]!=4){
				cnt=n-(i+1)+1;
				break;
			}
		}
		if(cnt>=m) cout<<"4";
		else{
			for(int i=1;i<=n;i++) cnt+=(a[i]==3);
			if(cnt>=m) cout<<"3";
			else{
				for(int i=1;i<=n;i++) cnt+=(a[i]==2);
				if(cnt>=m) cout<<"2";
				else{
					for(int i=1;i<=n;i++) cnt+=(a[i]==1);
					if(cnt>=m) cout<<"1";
					else cout<<"0";
				}
			}
		}
		return 0;
	}
	dfs(1,0,(1<<30)-1);
	cout<<ans;
	return 0;
}
