#include <bits/stdc++.h>
using namespace std;
long long s[100000000],s1[100000000],a[200005],n,ming;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=0;i<n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		for(int j;j<=a[i];j++){
			s[t]=c[i];
			t++;
		}
	}
	t=0;
	for(int i=n;i>=1;i++){
		for(int j;j<=a[i];j++){
			s1[t]=c[i];
			t++;
			if(s[t]!=s1[t]){
				ming++;
			}
		}
	}
	printf("%lld",ming);
	return 0;
}
