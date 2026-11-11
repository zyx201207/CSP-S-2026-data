#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long a[N];
char c[N];
long long n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1,j=n;i<j;){
		if(a[i]>a[j]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}else{
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
	}
	printf("%lld",ans);
	return 0;
}

