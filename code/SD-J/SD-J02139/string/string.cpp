#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll n,flag=1,sum=0,nn,ans=0;
ll a[N];
char c[N];
string pp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (ll i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for (ll i=1;i<=n;i++)
		if (c[1]!=c[i]){
			flag=0;
			break;
		}
	if (flag==1){
		cout << 0;
		return 0;
	}
	for (int i=1;i<=n;i++)
		sum+=a[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++)
			pp+=c[i];
	}
	ll mid=(sum+1)/2;
	for (int i=0;i<mid;i++){
		if (pp[i]==pp[sum-i+1])
			ans++;
	}
	cout << ans;
	return 0;
} 
