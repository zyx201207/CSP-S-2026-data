#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long Max=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            Max=max(Max,a[i]&a[j]);
        }
    }
    cout<<Max;
    return 0;
}

