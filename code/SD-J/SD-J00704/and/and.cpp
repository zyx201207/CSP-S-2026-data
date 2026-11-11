#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,ans,dp[N][2],a[N],h;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(m==1) {
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
	}
	else if(n==m) {
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		} 
	}
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

