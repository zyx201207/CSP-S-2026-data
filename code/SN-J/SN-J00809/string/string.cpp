//王子畅 西安市含光中学 SN-J00809 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,num[200050],ln,ans;
char c[1000000050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		char cs;
		cin>>cs;
		for(ll j=ln+1;j<=ln+k;j++){
			c[j]=cs;
		}
		ln+=k;
	}
	for(int i=1;i<=ln/2;i++){
		if(c[i]!=c[ln-i+1]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}

