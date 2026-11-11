#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=10*res+ch-'0';
        ch=getchar();
    }
    return res*f;
}
void outt(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    char ch=x%10+'0';
    if(x>=10){
        outt(x/10);
    }
    putchar(ch);
}
const int N=5e5+5;
const int M=3e5+5;
ll n,m,a[N],in[M],id;
ll vall[M],lastt[M];
vector<int> e[M];
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        vall[a[i]]++;
        lastt[a[i]]=0;
    }
    for(int i=n;i>=1;i--){
        if(lastt[a[i]]==0){
            lastt[a[i]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(lastt[i]==n)continue;
        e[i].push_back(a[lastt[i]+1]);
        in[a[lastt[i]+1]]++;
    }
    for(int i=1;i<=m;i++){
        if(!in[i]){
            q.push(i);
        }
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i];
            vall[v]=vall[v]+vall[u];
            in[v]--;
            if(!in[v]){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=m;i++){
        outt(vall[i]);
        putchar(' ');
    }
    return 0;
}

