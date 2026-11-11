#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200005
int n;
struct node{
    int n,c;
}a[maxn];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i].n>>c;
        a[i].c=c-'a';
    }
    int l=1,r=n,ans=0;
    for(;l<r;){
        while(!a[l].n&&l<r) l++;
        while(!a[r].n&&l<r) r--;
        int m=min(a[l].n,a[r].n);
        if(a[l].c!=a[r].c){
            ans+=m;
        }
        a[l].n-=m;
        a[r].n-=m;
    }
    cout<<ans<<endl;
    return 0;
}
