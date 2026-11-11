//李沐阳 SN-J00803 西安交通大学附属中学兴庆校区 初一年级
#include<bits/stdc++.h>
using namespace std;
long long n,l=0,a,ans=0;
char c,s[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a,&c);
		for(long long j=l+1;j<=l+a;j++)s[j]=c;
		l+=a;
	}
	for(long long i=1;i<=l/2;i++)if(s[i]!=s[l-i+1])ans++;
	cout<<ans;
	return 0;
}
