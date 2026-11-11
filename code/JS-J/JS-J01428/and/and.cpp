#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool against=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i&&a[i]<a[i-1]) against=1;
    }
    if(against) sort(a,a+n,cmp);
    int ans=a[0];
    for(int i=1;i<m;i++) ans&=a[i];
    cout<<ans;
    return 0;
}
