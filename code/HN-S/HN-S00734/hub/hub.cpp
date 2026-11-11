#include<bits/stdc++.h>
using namespace std;
int read(){
    int res=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
    while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}
int c,_,n,k;
vector<int>tree[1145141];
void init(){for(int i=0;i<1145141;++i)tree[i].clear();}
struct node{int id,cnt;};
void solve(){
    init();n=read();k=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    if(n==k){printf("0");return;}
    printf("%d\n",ceil(((n+1>>1)-k)>>2));
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();_=read();
    while(_--)solve();
}