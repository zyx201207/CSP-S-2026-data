#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    long long a[n];
    long long maxv=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxv=max(maxv,a[i]);
    }
    if(m==1){
        printf("%d",maxv);
        return 0;
    }
    if(m==n){
        long long sum=a[0]&a[1];
        for(int i=2;i<n;i++){
            sum=sum&a[i];
        }
        printf("%d",sum);
        return 0;
    }
    if(m==2){
        long long sum=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum=max(sum,a[i]&a[j]);
            }
        }
        printf("%d",sum);
        return 0;
    }else{
        printf("0");
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
