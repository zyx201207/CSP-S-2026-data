#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j] < a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    int sum=0;
    for(int i=1;i<n;i++){
        sum=max(sum,a[i]&a[i+1]);
    }
    cout<<sum;
    return 0;
}
