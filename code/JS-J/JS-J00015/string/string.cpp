#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;long long cnt=0;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
    int l=1,r=n;
    while(l<r){
        if(a[l].c==a[r].c){
            int mn=min(a[l].x,a[r].x);
            a[l].x-=mn,a[r].x-=mn;
            if(a[l].x==0)l++;
            if(a[r].x==0)r--;
        }else{
            int mn=min(a[l].x,a[r].x);
            a[l].x-=mn,a[r].x-=mn;
            if(a[l].x==0)l++;
            if(a[r].x==0)r--;
            cnt+=mn;
        }
    }
    cout<<cnt;
    return 0;
}
