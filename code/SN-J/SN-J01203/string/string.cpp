#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N];
char c[N];
string s;
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	
	ll cnt=0;
	if(sum&1){
		cnt=sum;
		sum=sum/2+1;
		for(int i=1;i<sum;i++){
			if(s[i-1]==s[cnt-i])continue;
			else ans++;
		}
		cout<<ans;
	}
	else{
		cnt=sum;
		sum/=2;
		for(int i=1;i<=sum;i++){
			if(s[i-1]==s[cnt-i])continue;
			else ans++;
		}
		cout<<ans;
	}
	return 0;
}
