#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll a[N];
char c[N];
int n;
ll sum=0,ans=0;
string s;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
