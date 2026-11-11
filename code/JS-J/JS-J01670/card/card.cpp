#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],cnt[1000005];
bool vis2[1000005];
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
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        queue<int>q;
        queue<int>tmp;
        for(int j=i;j<=n;j++){
            if(!vis2[a[j]]){
                vis2[a[j]]=1;
                q.push(a[j]);
            }else{
                while(q.front()!=a[j]){
                    tmp.push(q.front());
                    q.pop();
                }
                while(!q.empty()){
                    q.pop();
                }
                while(!tmp.empty()){
                    q.push(tmp.front());
                    tmp.pop();
                }
                q.push(a[j]);
                }
        }
        if(!q.empty()){
            int x=q.front();
            cnt[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
}