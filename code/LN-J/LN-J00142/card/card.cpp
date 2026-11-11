#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    cout<<n;
    for(int i=0;i<m-1;i++){
        cout<<" "<<a[i];
    }
    return 0;
}
