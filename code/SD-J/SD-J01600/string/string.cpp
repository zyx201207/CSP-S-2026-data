#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans,len;
char c[200005];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) ans++;
	}
	printf("%ld",ans);
	return 0;
} 

