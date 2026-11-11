#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using lnt=long long;
/*====================*/
const int N=5e5+10;
lnt n,m,a[N],b[N],x,y;
/*====================*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	/*====================*/
	cin>>n>>m;
	if(n<=5e3){
		lnt ans=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			lnt sum=0,cnt=1;
			for(int j=i-1;j>=1;j--) if(sum+a[i]-a[j]<=m) sum+=a[i]-a[j],cnt++;
			ans=max(ans,cnt);
		}
		cout<<ans;		
	}
	else{
		for(int i=1;i<n;i++) cin>>x;
		cin>>y;
		lnt d=abs(y-x),cnt=0,ans=1;
		while(cnt<=m) cnt+=ans*d,ans++;
		cout<<ans-1;
	}
	/*====================*/
	return 0;
}
