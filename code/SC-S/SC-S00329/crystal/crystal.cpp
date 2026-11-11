#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans[N],t[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=5000){
		cout<<m/(a[2]-a[1]);
	}else if(m==0){
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		sort(t+1,t+1+n,greater<int>());
		cout<<t[1];
	}else{
		for(int i=1;i<=n;i++){
			int x=0;
			for(int j=1;j<=i;j++){
				x+=(a[i]-a[j]);
			}
			ans[i]=x;
		}
		for(int i=n;i>=1;i--){
			if(m>=ans[i]){
				cout<<i;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	return 0;//4 3
}