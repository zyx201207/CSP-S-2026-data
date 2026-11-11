#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        int mins=a[i];
        for(int j=i-1;j<=n;j++){
            if(a[j]<a[mins]){
                swap(a[j],a[mins]);
            }
            mins=j;
        }
    }
    cout<<a[m];
    return 0;
}
