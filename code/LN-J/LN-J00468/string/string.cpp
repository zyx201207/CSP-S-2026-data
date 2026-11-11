#include<bits/stdc++.h>
using namespace std;

#define int long long
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}
const int N = 2e5+10;
struct node{
    int a;
    char c;
}s[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n=read();
    for(int i = 1; i <= n; i++){
        s[i].a=read();
        cin >> s[i].c;
    }
    int i = 1, j = n,ans=0;
    while(i < j){
        if(s[i].c == s[j].c){
            if(s[i].a>=s[j].a)s[i].a-=s[j].a,j--;
            else s[j].a-=s[i].a,i++;
        }
        else{
            if(s[i].a>=s[j].a)ans+=s[j].a,s[i].a-=s[j].a,j--;
            else ans+=s[i].a,s[j].a-=s[i].a,i++;
        }
    }
    printf("%lld",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

