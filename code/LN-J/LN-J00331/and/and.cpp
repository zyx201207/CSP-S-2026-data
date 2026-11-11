#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans;
bool cmp(int a,int b) {
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    if(m==1) {
        cout<<a[0];
        return 0;
    }
    ans=a[0];
    m--;
    int i=1;
    while(m){
        ans&=a[i];
        m--,i++;
    }
    cout<<ans;
}
