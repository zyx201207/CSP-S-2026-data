#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d %c",a+i,c+i);
    long long ans=0;int l=1,r=n;
    while(l<r){
    	if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r--];
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l++];
			if(a[r]==0)--r;
		}
	}
	printf("%lld",ans);
    return 0;
}
