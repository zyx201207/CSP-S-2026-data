#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
ll n;
struct str{ll c; char x;}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].c>>a[i].x;
	ll L=1,R=n,sum=0;
	while(L<=R){
		ll cnt=0,ans=0;
		for(int i=R;i>L;i--){
			R=i;
			if(cnt+a[i].c>a[L].c&&a[i].x!=a[L].x){
				ll old=cnt;
				cnt+=a[L].c-old,ans+=a[L].c-old,a[i].c-=cnt;
				break;
			}
			else if(cnt+a[i].c>a[L].c&&a[i].x==a[L].x){cnt+=a[L].c-cnt; a[i].c-=cnt; break;}
			else if(cnt+a[i].c<=a[L].c&&a[i].x!=a[L].x){cnt+=a[i].c,ans+=a[i].c;}
			else cnt+=a[i].c;
		}
		sum+=ans;
		L++;
	}
	printf("%lld",sum);
	return 0;
}
/*
3
2 a
2 b
1 c
*/