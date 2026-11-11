#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct range{
    int cnt;
    char ch;
}ss[N];
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        ss[i].cnt=read();
        ss[i].ch=getchar();
    }
    int i=1,j=n+1-i,ans=0;
    for(;i<j;){
        int l=ss[i].cnt,r=ss[j].cnt;
        char c1=ss[i].ch,c2=ss[j].ch;
        if(l==r){
            if(c1==c2){i++,j--;continue;}
            else {ans+=l,i++,j--;continue;}
        }
        else{
            if(l>r){
                if(c1==c2){
                    ss[i].cnt-=r;
                    j--;continue;
                }
                else{
                    ss[i].cnt-=r;
                    j--;ans+=r;continue;
                }
            }
            else{
                if(c1==c2){
                    ss[j].cnt-=l;
                    i++;continue;
                }
                else{
                    ss[j].cnt-=l;
                    i++;ans+=l;continue;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
