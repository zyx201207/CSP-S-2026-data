#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],x=1,ans;
char s[200005],t;
int main(){
	fropen("string.in","r",stdin);
	fropen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(n>x){
		if(s[n]!=s[x]){
			ans+=min(a[x],a[n]);
		}
		a[x]-=min(a[x],a[n]);
		a[n]-=min(a[x],a[n]);
		if(a[x]==0){
			x++;
		}
		if(a[n]==0){
			n--;
		}
	}
	cout<<ans;
	return 0;
}