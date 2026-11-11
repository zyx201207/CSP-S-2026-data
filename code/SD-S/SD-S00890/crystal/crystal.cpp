#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
void fun(){
	__int128 sum;
	int ans=1,cnt;
	for(int i=1;i<n;++i){
		sum=0,cnt=1;
		for(int j=i+1;j<=n;++j){
			if(!sum&&sum+(a[j+1]-a[j])<=m) sum+=a[j+1]-a[j],cnt++;
			else if(sum+(a[j+1]-a[j])*2<=m) sum=sum+(a[j+1]-a[j])*2,cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}

void fun_2(){
	int x=a[2]-a[1];
	int y=sqrt(2*m/x)+1;
	cout<<y;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000) fun();
	else fun_2();
	return 0;
}
