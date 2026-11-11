#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(int &a){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return a=x*f;
}
const int N=310;
int d[N];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    read(c),read(t);
    while(t--){
        int n,k;
        read(n),read(k);
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            d[a]++;
            d[b]++;
        }
        if(k==n){
            cout<<"0\n";
            continue;
        }
        else{
            cout<<"1\n";
            continue;
        }
    }
}