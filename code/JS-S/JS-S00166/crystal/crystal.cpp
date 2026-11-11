#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],k;
int n,i,j,d;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1;i++)
        a[i]=a[i+1]-a[i];
    for(i=0;i<n-1;i++){
        while(k<=m&&j<n){
            j++;
            k=k+(j-i)*a[j-1];
        }
        if(k>m)j--;
        d=max(d,j-i+1);
        k-=(j-i)*a[i];
    }
    cout<<d;
    return 0;
}
