#include<bits/stdc++.h>
using namespace std;
int n;
struct area{
    long long x;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    //
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(a[l].c!=a[r].c)ans+=min(a[l].x,a[r].x);
        if(a[l].x<a[r].x)a[l].x=0,a[r].x-=a[l].x,l++;
        else if(a[l].x>a[r].x)a[l].x-=a[r].x,a[r].x=0,r--;
        else if(a[l].x==a[r].x)a[l].x=a[r].x=0,l++,r--;
    }
    cout<<ans;
    return 0;
}
