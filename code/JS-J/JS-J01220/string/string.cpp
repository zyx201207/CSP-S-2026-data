#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5;
struct node{
    int l,w;
    char c;
}a[N];
string s;
int n,ans,tot;
int pos;
int l[N],r[N],stp[N];
void prep();
void init();
void dr();
void work();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int T=1;
//    cin>>T;
    prep();
    while(T--){
        init();
        dr();
        work();
    }
    return 0;
}
void prep(){
}
void init(){
}
void dr(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].c,pos+=a[i].c;
}
void work(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=a[i].l;j++) s+=a[i].c;
    //cout<<s<<' ';
    for(int i=0,j=s.size()-1;i<=j;i++,j--) ans+=!(s[i]==s[j]);
    cout<<ans;
}
//TLE 68pts
