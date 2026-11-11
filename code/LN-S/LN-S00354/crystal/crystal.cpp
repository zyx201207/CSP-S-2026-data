#include<bits/stdc++.h>
using namespace std;
int ns,m,c[500002],sum=-999,a[500002];
bool banana=1;
int ans(int n,int m){

    int sam=0;
    int b=a[n];//5 5
    while(1){//  1 2 4
        if(a[n]==b){
            n-=1;
            sam++;
        }else if(m==0){
            break;
        }else{
            while(1){
                m--;
                a[n]++;
                if(a[n]==b){
                    break;
                }
                if(m==0){
                    break;
                }
            }
        }
        if(n==0){
            break;
        }
    }
    sum=max(sum,sam);
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>ns>>m;
    for(int i=1;i<=ns;i++){
            cin>>a[i];
            c[i]=a[i];
    }
    sort(a+1,a+ns+1);
    sort(c+1,c+ns+1);
    for(int i=ns;i>=2;i--){

        ans(i,m);
        for(int i=1;i<=ns;i++){
           a[i]=c[i];
        }
    }
    banana=1;
    cout<<sum;
    return 0;
}
