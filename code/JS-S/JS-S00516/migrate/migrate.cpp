#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
        int n,d,a[2000005],sum=0;
        scanf("%d %d",&n,&d);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int r=1,s=1,l1=0,l2=0;
                for(int k=i;k<j;k++){
                    if(a[k+1]-a[k]<=d){
                        while(a[k+r]-a[k]<=d){
                            r++;
                        }
                        k+=r;
                        l1++;
                    }
                }
                for(int k=j;k>i;k--){
                    if(a[k]-a[k-1]<=d){
                        while(a[k]-a[k-s]<=d){
                            s++;
                        }
                        k-=s;
                        l2++;
                    }
                }
                if(l1==l2)sum++;
            }
        }
        printf("%d",sum/5-1);
    }
    return 0;
}
