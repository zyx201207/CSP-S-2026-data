#include<bits/stdc++.h>
using namespace std;

long long l,cnt;
int n,a[200005];
char c[200005],ch,s[100000005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%c%c%c",&a[i],&ch,&c[i],&ch),l+=a[i];
	if(l<=100000000){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++)
				s[++cnt]=c[i];
		}
		for(int i=1;i<=l/2;i++){
			int j=l-i+1;
			if(s[i]!=s[j])
				ans++;
		}
		printf("%lld",ans);
	}
	return 0;
}