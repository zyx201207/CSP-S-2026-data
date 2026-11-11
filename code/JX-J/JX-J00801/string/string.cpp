#include<bits/stdc++.h>
using namespace std;
int n;
struct asdf{
    long long sl;
    char c;
}a[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].sl;
        cin>>a[i].c;
        //cout<<i<<'\n';
    }
    //cout<<1000000<<'\n';
    int l=1,r=n;
    while(l<r){
        if(a[l].c==a[r].c){
            long long minn=min(a[l].sl,a[r].sl);
            a[l].sl-=minn;
            a[r].sl-=minn;
        }else{
            long long minn=min(a[l].sl,a[r].sl);
            a[l].sl-=minn;
            a[r].sl-=minn;
            ans+=minn;
        }
        if(a[l].sl==0)l++;
        if(a[r].sl==0)r--;
    }
    cout<<ans;
    return 0;
}
