#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct zf{
	int x;
	char m;
};
int n,suml,a,sumx,half,halfx,sumy,k,ans;
zf s[200005];
char u;
bool flag=true;
string st="";
signed main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a,&u);
		s[i].x=a;
		s[i].m=u;
		suml+=a;
		if(i>=2&&u!=s[i-1].m) flag=false;
	}
	if(flag){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i].x;j++){
			st+=s[i].m;
		}
	}
	if(suml%2==0){
		for(int i=0,j=suml-1;i<=suml/2-1,j>suml/2-1;i++,j--){
			if(st[i]!=st[j]) ans++;
		}
		printf("%lld",ans);
	}
	else{
		for(int i=0,j=suml-1;i<=suml/2-1,j>suml/2;i++,j--){
			if(st[i]!=st[j]) ans++;
		}
		printf("%lld",ans);
	}
}