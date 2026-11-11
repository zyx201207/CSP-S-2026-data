#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#define int long long
using namespace std;
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
const int N=5e5+10;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
//	cout<<a[1]<<' '<<a[2]<<endl;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int cnt=a[j]*(j-i+1)-(s[j]-s[i-1]);
				if(cnt>m)break;
				ans=max(ans,j-i+1);
//				cout<<i<<' '<<j<<' '<<cnt<<' '<<j-i+1<<endl;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int cnt=a[i]*i-s[i];
			if(cnt>m)break;
			ans=i;
		}
	}

	
	cout<<ans;
	return 0;
}
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释
//一定要去注释

