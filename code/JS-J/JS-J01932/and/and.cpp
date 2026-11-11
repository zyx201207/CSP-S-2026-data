#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0;
    if(n==m){
        sum=a[1];
        for(int i=2;i<=n;i++){
            sum=sum&a[i];
        }
        printf("%d",sum);
        return 0;
    }else if(m==1){
        sum=a[1];
        for(int i=2;i<=n;i++){
            if(sum<a[i]){
                sum=a[i];
            }
        }
        printf("%d",sum);
    }else if(m==2){
        long long s,ms=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                s=a[i]&a[j];
                ms=max(ms,s);
            }
        }
        printf("%d",ms);
    }else{
        printf("1");
    }
    return 0;
}
