#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int read(){
    int s=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x<10){putchar(x+48);return;}
    else{write(x/10);putchar(x%10+48);}
}
int a[N],n,m,ans[N],instk[3005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;n=read();m=read();
    int f=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i-1]>a[i]) f=0;
    }
    if(f){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                ans[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++) write(ans[i]),putchar(' ');
        return 0;
    }
    else{
        stack<int> st;
        for(int i=1;i<=n;i++){
            memset(instk,0,sizeof(instk));
            for(int j=i;j<=n;j++){
                if(!instk[a[j]]){
                    st.push(a[j]);
                
                    instk[a[j]]=1;
                }
                else{
                    while(!st.empty()&&st.top()!=a[j]){
                        instk[st.top()]=0;
                        st.pop();
                    }
                }
            }
            for(int i=1;i<=n;i++) ans[i]+=instk[i];
        }
        for(int i=1;i<=m;i++) write(ans[i]),putchar(' ');
    }
    return 0;
}