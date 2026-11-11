#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+5;
struct node{
    char c;
    int x;
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        string s;
        cin>>t;cin>>s;
        if(a[m].c==s[0]) a[m].x+=t;
        else{
            a[++m].x=t;
            a[m].c=s[0];
        } 
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    // for(int i=1;i<=m;i++) cout<<a[i].c<<'\n';
    int ans=0,l=1,r=m;
    for(;l<r;){
        if(a[l].c==a[r].c){
            int t=min(a[l].x,a[r].x);
            a[l].x-=t,a[r].x-=t;
            if(a[l].x==0) l++;
            if(a[r].x==0) r--;
        }else{
            int t=min(a[l].x,a[r].x);
            a[l].x-=t,a[r].x-=t;
            ans+=t;
            if(a[l].x==0) l++;
            if(a[r].x==0) r--;
            // cout<<"a:"<<t<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// g++ string.cpp -o string; ./string; diff string.out string1.ans