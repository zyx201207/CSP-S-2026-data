#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010],ans[300010];
long long lst[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long l=0;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            lst[j]=0;
        }
        for(long long j=i;j<=n;j++){
            if(lst[a[j]]==0){
                lst[a[j]]++;
                b[++l]=a[j];
            }else{
                while(b[l]!=a[j]){
                    lst[b[l]]--;
                    l--;
                }
            }
        }
        for(long long j=1;j<=m;j++){
            if(lst[j]){
                ans[j]++;
            }
        }
    }
    for(long long i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }
	return 0;
}

