#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll b[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=0;
	}
	freopen("crystal.in","r",stdin);
	sort(a+1,a+n+1);//0->1
	ll mid;
	if(n%2==1){
		mid=a[(n+1)/2];
	}
	else{
		mid=a[n/2];
	}
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-mid);
	}
	sort(b+1,b+n+1);
	ll ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		ans+=b[i];
		cnt++;
		if(ans>m){
			cnt-=1;
			break;
		}
		if(ans==m){
			break;
		}
	}
	cout<<cnt;
	freopen("crystal.out","w",stdout);
	return 0;
} 