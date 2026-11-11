#include<bits/stdc++.h>
using namespace std;
int n,a[200001],b[200001],c[50000000],cnt,num,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    if(sum==n){
        cout<<n-1;
        return 0;
    }
    for(int i=1,j=num;i<=n;i++){
        for(;j<a[i]+num;j++){
            c[j]=b[i];
            num++;
        }
    }
    for(int i=0,j=num;i<j;i++,j--){
        if(c[i]!=c[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
