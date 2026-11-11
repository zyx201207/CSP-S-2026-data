#include<bits/stdc++.h>
using namespace std;
string s;
long long n,len,a,ans;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		scanf("%lld %c",&a,&x);
		len+=a;
		while(a--) s+=x;
	}
	long long i=0,j=len-1;
	while(i<j){
		if(s[i]!=s[j]) ans++;
		i++,j--;
	}
	printf("%lld",ans);
	return 0;
}
