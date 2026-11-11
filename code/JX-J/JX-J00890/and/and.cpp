#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N],sum,zd=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>2000){
        cout<<a[n-m+1];
        return 0;
    }
    for(int i=1;i<=n;i++){
            sum=a[i];
        for(int j=i+1;j<=n;j++){
            int p=j;
            for(int k=1;k<m;k++){
                sum=sum&a[p];
                p++;
            }
            zd=max(sum,zd);
        }
    }
    cout<<zd;
    return 0;
}
