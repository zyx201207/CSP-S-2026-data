#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int ans;
struct node{
    int num;
    char ch;
    void in(){
        cin>>num>>ch;
    }
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) a[i].in();
    int l=1,r=n;
    while(l<r){
        int minn=min(a[l].num,a[r].num);
        if(a[l].ch!=a[r].ch) ans+=minn;
        a[l].num-=minn;
        a[r].num-=minn;
        if(a[l].num==0) l++;
        if(a[r].num==0) r--;
    }
    cout<<ans<<"\n";
    return 0;
}
