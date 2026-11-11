#include<bits/stdc++.h>
using namespace std;
int n,m;
struct in{
	bool you;
	int start;
	long long ans;
}a[300005];
long long b[500005],kou[500005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	long long t=b[1];
	for(int i=1;i<=n;i++){
		if(b[i]!=t){
			t=b[i];
			a[t].ans++;
		}
		else{
			a[t].ans++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",a[i].ans+a[i-1].ans);
		a[i].ans+=a[i-1].ans;
	}
	return 0;
} 
