#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],l,r,ans;
string s[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(l<r){
		if(s[l]!=s[r]) {
			ans++;
		}
		a[l]-=1;
		a[r]-=1;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		if(r==l)break;
	}
		cout<<ans;
	return 0;
}
