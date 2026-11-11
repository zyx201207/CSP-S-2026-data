#include<bits/stdc++.h>
using namespace std;
long long n,a[3000000],sum,k;
string s,s1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s1+=s[i];
		}
	}
	for(int i=0;i<sum/2;i++){
		if(s1[i]!=s1[sum-i-1]){
			k++;
		}
	}
	cout<<k;
	return 0;}

