#include <bits/stdc++.h>
using namespace std;
int m,n,xmax;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    for(int i=m;i>=n;i--){
        int x=a[i];
        for(int j=1;j<n;j++){

            x= x & a[i-j];

        }
        if(x>xmax){
            xmax=x;
        }
    }
    cout<<xmax;
    return 0;
}

