#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005];
char c[200005];
ll s=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%ld",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	if(n==1)cout<<0;
	else{
		string ss="";
		ll m=(s+1)/2,ans=0;
		for(int i=1;i<=n;i++){
			while(a[i]--){
				ss+=c[i];
			}
		}
		for(int i=0;i<m;i++){
			if(ss[i]!=ss[s-i-1]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
