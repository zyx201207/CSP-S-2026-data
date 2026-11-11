#include<bits/stdc++.h>
using namespace std;
unsigned int n,m,ans;
unsigned int a[210000000];
bool cmp(unsigned int a1,unsigned int a2){
    return a1>a2;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    ans=a[0];
    for(int i=1;i<m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
