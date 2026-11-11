#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[200005],b[200005],c[200005],x=INT_MIN;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        c[i]=1;
        for(int j=0;j<i;j++) if(b[j]&b[i]>=b[i]&&c[j]+c[i]<=m) b[i]=b[j]&b[i],c[i]=c[j]+c[i];
    }
    for(int i=0;i<n;i++) x=max(a[i],x);
    cout<<x;
    return 0;
}
