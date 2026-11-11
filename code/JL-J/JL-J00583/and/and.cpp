#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010]={},ma1;
void mm(int a1){
    if(a1==n){
        return;
    }
    ma1=max(ma1,a[a1]&ma1);
    //cout<<a1;
    for(int i=a1+1;i<n;i++){
        mm(i);
    }
    a1--;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ma1=a[0];
    mm(0);
    sort(a,a+n);
    cout<<a[n-1];
    return 0;
}
