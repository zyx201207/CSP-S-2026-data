#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x=0,t[500005];
bool f=1,b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n==1){
		printf("1");
		return 0;
	}else{
		scanf("%lld%lld",&a[0],&a[1]);
	}
	
    x=abs(a[0]-a[1]);
    for(long long i=2;i<n;i++){
		scanf("%lld",&a[i]);
		if(abs(a[i]-a[i-1])!=x){
            f=0;
		}
	}
	long long ma_l=0;
	for(long long i=0;i<n;i++){
        if(a[i]==1||a[i]==0){
			f=1;
            continue;
        }else if(!b[i]){
            t[0]=a[i];
            long long last=a[i],l=1;
            for(long long j=i+1;j<n;j++){
                if(a[j]%last==0){
                    last=a[j];
                    l++;
                    t[l]=a[j];
                    b[j]=1;
                }
            }
            if(l>ma_l){
                ma_l=l;
            }
        }
	}
	if(f){
		ma_l++;
	}
	long long ans=0,ta=2,x=1;
	while(ans<m){
        ans+=ta;
        ta++;
        x++;
	}
	if(x>ma_l){
        printf("%lld",ma_l);
	}else{
        printf("%lld",x);
	}
    return 0;
}
