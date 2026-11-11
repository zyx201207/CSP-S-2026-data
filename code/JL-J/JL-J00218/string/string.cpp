#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;

struct node{int num;char c;}a[N];
int n;
int ans;

signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    int l=1,r=n;
    while(l<r){

        int temp=min(a[l].num,a[r].num);
        a[l].num-=temp,a[r].num-=temp;

        if(a[l].c!=a[r].c)
            ans+=temp;

        if(a[l].num==0) l++;
        if(a[r].num==0) r--;

    }
    cout<<ans<<'\n';
    return 0;
}
