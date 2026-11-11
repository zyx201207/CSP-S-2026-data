#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#define ll long long

using namespace std;

const int N=1e6+5;
ll tp[N];
ll b11[N];
ll pp[N];
string z="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	ll op=0;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		ll a;
		char b;
		scanf("%lld", &a);
		cin >> b;
		for (int i=1;i<=a;i++){
			z+=b;
		}
	}
	ll sz=z.size();
	ll ans=0;
	if (sz%2==1){
		
		for (int i=0;i<sz/2;i++){
			if (z[i]!=z[sz-i-1]) ans++;
		}
	}
	else {
		for (int i=0;i<=sz/2-1;i++){
			if (z[i]!=z[sz-i-1]) ans++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
