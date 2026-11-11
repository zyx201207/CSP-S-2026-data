#include<bits/stdc++.h>
using namespace std;\
int n,a[200007];long long ans;char c[200007];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);cin>>c[i];
	}long long l=a[1],r=a[n],xbl=1,xbr=n;char zfl=c[1],zfr=c[n];
	while(xbl+1<=xbr){
		if(l>r){
			if(zfl!=zfr){
				ans+=r;
			}
			l-=r;
			xbr--;
			r=a[xbr];
			zfr=c[xbr];
		}else if(l<r){
			if(zfl!=zfr){
				ans+=l;
			}
			r-=l;
			xbl++;
			l=a[xbl];
			zfl=c[xbl];
		}else{
			if(zfl!=zfr){
				ans+=r;
			}
			xbl++;
			l=a[xbl];
			xbr--;
			r=a[xbr];
			zfr=c[xbr];
			zfl=c[xbl];
		}
	}cout<<ans<<endl;
    return 0;
}
