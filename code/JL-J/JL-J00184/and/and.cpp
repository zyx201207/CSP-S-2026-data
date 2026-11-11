#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>>a[i+m]>maxn){
            maxn=a[i]>>a[i+m];
        }
    }
    cout<<maxn;
    return 0;
}
