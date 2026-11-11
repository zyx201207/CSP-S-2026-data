#include <bits/stdc++.h>
using namespace std;
int n,d[1000005],m;
long long tot=0,ans=0;
char a;
string s;
queue<pair<int,char> > q1,q2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&d[i],&a);
		tot+=d[i];
		for(int j=1;j<=d[i];j++){
			s+=a;
		}
	}
	for(int i=0;i<tot/2;i++){
		if(s[i]!=s[tot-i-1]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
