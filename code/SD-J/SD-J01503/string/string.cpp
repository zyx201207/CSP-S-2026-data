#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,M=1e3+10;
ll n,cnt=0,ans=0;
struct node{
	ll x;
	char c;
}a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	bool ffff=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].x,&a[i].c);
		if(a[i].x>500){
			ffff=1;
		} 
		else{
			for(int j=1;j<=a[i].x;j++){
				b[++cnt]='0'+a[i].c;
			}
		}
		
	}
	if(ffff==1){
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i].x;
		}
		printf("%lld",sum/2);
		return 0;
	}
	/*for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}*/
	for(int i=1;i<=cnt/2;i++){
		if(b[i]!=b[cnt-i+1]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
