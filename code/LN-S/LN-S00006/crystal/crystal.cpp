#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m=0,n=0,a[500005]={},k=1,f1=0,f=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    while(m>=k){
            f1=f;
        f=a[k+1]-a[k];
        if(m>=k*f){
            m=m-f*k;
            a[k]=a[k+1];
            k++;
        }
    }
    while(true){
        if(a[k]==a[k+1]){
            k++;
        }else{
            break;
        }
    }

    cout<<k;
return 0;

}
