#include<bits/stdc++.h>
#define ll long long
const ll N=5e5+10;
ll n,m;
unsigned long long cnt;
ll a[N];
using namespace std;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++){
		cnt+=(i-1)*(a[i]-a[i-1]);
		if(cnt>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
	
	fclose(stdin);
	fclose(stdout);
	
} 
