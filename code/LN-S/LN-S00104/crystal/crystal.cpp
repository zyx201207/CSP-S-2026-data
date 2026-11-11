#include<bits/stdc++.h>
using namespace std;
long long a[100000005],b[10000005];
int main(){
freopen("crystal.in","w",stdin);
freopen("crystal.out","r",stdin);
    int n,m,num=0,c=0,d=INT_MIN;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=m;k++){
            a[k]++;
            c++;
            if(a[n]==a[k]||a[n]==a[k-c]){
                b[j]++;
            }
        }
        c=0;
    }
    for(int l=1;l<=m;l++){
        if(b[l]>d){
            d=b[l];
        }
    }
    cout<<d;
    return 0;
}
