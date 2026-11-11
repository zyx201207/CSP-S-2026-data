#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],s[N],fronti,backi,ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%ld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		scanf(" %c",&c[i]);
	}
	fronti=1,backi=n,ans=0;
	while(fronti<backi){
		if(c[fronti]!=c[backi]){
			ans+=min(a[fronti],a[backi]);
		}
		if(a[fronti]>a[backi]){
			a[fronti]-=a[backi];
			backi--;
		}else if(a[fronti]<a[backi]){
			a[backi]-=a[fronti];
			fronti++;
		}else{
			fronti++,backi--;
		}
	}
	cout<<ans;
	return 0;
}

