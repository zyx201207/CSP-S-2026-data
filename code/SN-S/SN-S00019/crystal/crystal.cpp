#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+5;
ll a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i];
//	}
	ll flag = a[n];
	int ans = 0;
	for(int i=3;i<=n;i++){
		int cnt=m;
		int num = 0;
		for(int j=i;j<=n;j++){
			cnt+=a[j];
//			cout<<cnt<<' '<<a[j]*[j]<<' ';
			if(cnt < a[j]*(j-i+1)){
				break;
			}
			num++;
		}
//		cout<<num<<endl;
		ans = max(ans,num);
		if(ans*2 > n && i*2 > n)break;
	}
	cout<<ans;
	return 0;
}
