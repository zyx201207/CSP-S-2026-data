#include<bits/stdc++.h>
using namespace std;
    const int INF=200005;
    long long ans,n,x,l,r,num[INF],tot;
    char a[INF];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&x);
    	cin>>a[i];
        num[i]=x;
        tot+=x;
	}
	l=1;r=n;
	for(int i=1;i<=tot/2;i++){
		if(a[l]!=a[r]){
			ans++;
		}
		num[l]--;num[r]--;
		if(num[l]<=0){
			l++;
		}
		if(num[r]<=0){
			r--;
		}
	}
	printf("%lld",ans);
}
