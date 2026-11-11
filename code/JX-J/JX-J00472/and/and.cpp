#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long int n,m;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i-1]>a[i]){
            swap(a[i-1],a[i]);
        }
    }
    if(m==2){
        int maxn=-1;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]&a[i]+1);
        }
        cout<<maxn;
        return 0;
    }
    if(m==1){
        cout<<a[n];
        return 0;
    }
    return 0;
}
