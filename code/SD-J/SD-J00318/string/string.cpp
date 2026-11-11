#include<bits/stdc++.h>
using namespace std;
int n,a;
long long ans,l;
char x;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		cin>>x;
		for(int j=1;j<=a;j++){
			s+=x;
		}
		l+=a;
	}
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-1-i]){
			s[l-1-i]=s[i];
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
