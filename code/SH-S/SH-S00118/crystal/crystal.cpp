#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500001];
long long c[500001];
int ans = 0;
bool check(int x,int y){
    long long u = c[y]-c[x-1];
    long long v = a[y]*1LL*(y-x+1);
    if(u+m>=v)
        return true;
    else
        return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    c[0]=0;
    for(int i = 1;i <= n;i++)
        c[i]=c[i-1]+a[i];
    for(int i = 1;i <= n;i++){
        int l = 0;
        int r = i+1;
        while(l+1<r){
        	int mid = (l+r)/2;
        	if(check(mid,i))
            	r=mid;
        	else
            	l=mid;
    	}
        ans=max(ans,i-r+1);
    }
    printf("%d",ans);
    return 0;
}
