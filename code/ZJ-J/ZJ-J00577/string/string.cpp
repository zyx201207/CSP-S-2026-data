#include <bits/stdc++.h>
#define ll long long
using namespace std;
//经读题可得 |S|不变
//即中心位置不变
//若|S|为偶数
//使1~|S|/2与|S|~|S|/2+1相同即可
//即算出差异
//若|S|为奇数
//使1~|S|/2与|S|~|S|/2+2相同即可
//nlogn时间复杂度模拟此过程 
ll a[200010];
char c[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i]; 
	}
	int l=1,r=n;
	ll s=0,ans=0;
	while(s<sum/2){
		if(a[l]>a[r]){
			a[l]-=a[r];
			if(c[l]!=c[r]){
				ans=min(ans+a[r],sum/2);
			}
			s+=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			s+=a[r];
			if(c[l]!=c[r]){
				ans=min(ans+a[r],sum/2);
			}
			l++,r--;
		}
		else{
			s+=a[l];
			if(c[l]!=c[r]){
				ans=min(ans+a[l],sum/2);
			}
			a[r]-=a[l];
			l++;
		}
	} 
	cout<<ans;
	return 0; 
}
//大样例全过
//好心人可以送我400pts吗？ 
