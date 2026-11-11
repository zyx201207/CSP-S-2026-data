#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[2000005];
char c[2000005];
string s;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int nn=s.size();
    for(int i=0;i<nn/2;i++){
        if(s[i]!=s[nn-i-1]){
            ans++;
        }
    }
    cout << ans;
}