#include <bits/stdc++.h>
using namespace std;
const int MAX=500000;
long long n,a[MAX+5],m;//共有n水晶，m次操作
int ans=1; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	long long sum = 0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	long long g=sum/n,k;
	for(int i = 1; i <=n; i++){
		if(g < a[i]){
			k = i - 1;
			break;
		}
	}
	for(int i=k;i>=1;i--){
		int j=a[i]-a[i-1];
		if(j <= m){
			a[i-1] += j;
			m-=j;
		}
		else{
			break;
		}
	}
	for(int i = 1;i <=n; i++){
		if(a[i]==a[i - 1]){
			ans++;
			
		}
	}
	if(ans>n){
		cout << n;
	}
	else{
		cout << ans;
	}
	return 0;
}
