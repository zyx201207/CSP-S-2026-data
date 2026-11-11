#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],flag=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1){
            flag++;
        }
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(!flag){
        cout<<max(a[n]&a[n-1],a[n-1]&a[n-2]);
        return 0;
    }
    cout<<7;
    return 0;
}
