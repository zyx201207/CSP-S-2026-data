#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,a[N],s[N];
int ans=INT_MIN;
void fun(){
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];           
	}
	sort(a+1,a+1+n);
	fun();
	for(int i=1;i<=n;i++){
		ll sum=a[i]*i-s[i];
		if(sum<=m){
			ans=max(i,ans);
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
