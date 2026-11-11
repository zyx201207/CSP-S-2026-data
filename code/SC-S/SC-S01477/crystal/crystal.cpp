#include<bits/stdc++.h>
#define int long long
#define ri register int
#define ls(x) x<<1
#define rs(x) x<<1|1
#define PINF 1e18
#define NINF 1e18
#define inf 500514
#define mf 5011
#define sf 1011
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int n,m,ans,num[inf],presum[inf];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ri i=1;i<=n;i++) cin >> num[i];
	sort(num+1,num+1+n);
	for(ri i=1;i<=n;i++) presum[i]=num[i]+presum[i-1];
	//初始化答案
	int tmprcd=0;
	for(ri i=1;i<=n;i++){
		if(i==1){
			tmprcd=1;
		}else{
			if(num[i]==num[i-1]) ans=max(ans,++tmprcd);
			else tmprcd=1;
		}
	}
	//开始滑动窗口
	int l=1;
	for(ri i=2;i<=n;i++){
		while(num[i]*(i-l+1)-(presum[i]-presum[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	
	cout << ans << endl;
	return 0;
}