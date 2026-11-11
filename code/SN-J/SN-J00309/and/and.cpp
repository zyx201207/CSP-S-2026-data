#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2020];
long long cnt,sum,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		cnt = max(cnt,1ll * a[i]);
	}
	if(m == 1){
		cout<<cnt;
	}
	else if(m == n){
		sum = a[0];
		for(int i = 1;i<n;i++){
			sum = sum & a[i];
		}
		cout<<sum;
	}
	else if(m == 2){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				ans = a[i] & a[j];
			}
		}
		cout<<ans;
	}
	return 0;
}
