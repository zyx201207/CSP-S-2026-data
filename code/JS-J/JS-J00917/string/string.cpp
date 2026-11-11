#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,p,q,ans;
int i,a[N];
char c[N];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        m=a[i];
        while(m--){
            s+=c[i];
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(c[1]==c[2]){
            cout<<0;
            return 0;
        }
        cout<<min(a[1],a[2]);
        return 0;
    }
    p=0;
    q=s.size()-1;
    while(p<q){
        if(s[p]!=s[q]){
            ans++;
        }
        p++,q--;
    }
    cout<<ans;
    return 0;
}
