#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N = 5e5+5;
int a[N],s[N];
int lst = 1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
 	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n == 1){
		cout<<1<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	int cnt = 0;
	long long sum = 0;
	int tmp = 1;
	for(int i=2;i<=n;i++){
		sum = sum+(a[i]-a[i-1])*tmp;
		tmp++;
		while(sum>m && lst<=i){
			sum -= a[i]-a[lst];
			lst++;
			tmp--;
		}
		if(sum>m){
			cout<<max(cnt,tmp)<<"\n";
			return 0;
		}
		cnt = max(cnt,tmp);
	}
	cout<<cnt<<"\n";
	return 0;
}
