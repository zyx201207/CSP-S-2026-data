#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,x=1;
int a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[n/2+1]==a[i]){
			ans++;
		}
		while(m>=0){
			a[n/2+1-x]++;
			m--;
			if(a[n/2+1]==a[n/2+1-x]){
				ans++;
				x++;
				a[i]-=x;
				break;
			}
		}
	}
	if(n%2==0){
		cout << ans+1;
	}else{
		cout << ans;
	}
	return 0;
} 
