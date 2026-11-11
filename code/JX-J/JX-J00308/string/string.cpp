#include <bits/stdc++.h>
using namespace std;
long long n,j=1,s,m;
struct str{
    long long a;
    char c;
}k[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    m=n;
    while(m--){
        cin>>k[j].a>>k[j].c;
        j++;
    }
    long long b=1,f=n,p=0,q=0;
    while(1){
        if(k[b].c!=k[f].c){
            s++;
        }
        //cout<<b<<k[b].c<<" "<<f<<k[f].c<<"\n";
        p++;
        q++;
        if(p==k[b].a){
            b++;
            p=0;
        }
        if(q==k[f].a){
            f--;
            q=0;
        }
        if(b>=f){
            cout<<s;
            break;
        }
    }
    return 0;
}
