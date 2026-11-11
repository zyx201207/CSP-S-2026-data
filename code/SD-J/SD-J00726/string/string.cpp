#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],sum,ans;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		sum+=a[i];
	}
	for(int i=0;i<=sum/2-1;i++){
		if(s[i]!=s[sum-i-1]) ans++; 
	}
	cout<<ans;
	return 0;
}

