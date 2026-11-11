#include<bits/stdc++.h>
using namespace std;
struct ch{
    long long x;
    char c;
};
long long n,ans,l1,r1;
ch a[200005];
ch l,r;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
    }
    l1=1;
    r1=n;
    l=a[l1];
    r=a[r1];
    while(l1<r1){
        if(l.c!=r.c){
            ans+=min(l.x,r.x);
        }
        if(l.x>=r.x){
            l.x-=r.x;
            r.x=0;
        }else{
            r.x-=l.x;
            l.x=0;
        }
        if(l.x<=0){
            l1++;
            l=a[l1];
        }
        if(r.x<=0){
            r1--;
            r=a[r1];
        }
    }
    cout<<ans;
    return 0;
}

