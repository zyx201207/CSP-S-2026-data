#include<bits/stdc++.h>
using namespace std;

int main(){

    long long m,n;
    cin>>n>>m;

    long long a[500010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxx=1;

    for(int j=n;j>=1;j--){
        long long maxx0=1;
        long long b[500010];
        long long m0=m;
        for(int k=1;k<=j;k++){
            b[k]=a[k];
        }
        for(int i=n-1;i>=1;i--){
            while(b[i]<b[i+1] && m0>0){
                b[i]=b[i]+1;
                m0-=1;
            }
            if(m0==0){
                break;
            }else{
                maxx0+=1;
                continue;
            }
        }
        if(maxx0>maxx){
            maxx=maxx0;
        }
    }

    cout<<maxx;

    return 0;
}
