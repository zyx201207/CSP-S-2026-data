#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[200200],cnt=0,l,r;
char c[200200];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
	}
	l=1;
	r=n;
	while(l<r){
		int x=min(a[l],a[r]);
		if(c[l]!=c[r]){
			cnt+=x;
			a[l]-=x;
			a[r]-=x;
		}else{
			a[l]-=x;
			a[r]-=x;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		//cout<<l<<' '<<r<<endl;
	}
	printf("%lld",cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
