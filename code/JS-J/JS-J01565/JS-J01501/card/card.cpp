#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200100;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        x=x*10+(int)(ch-48);
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    n=read();
    m=read();
    int a[N]={};
    int t[N]={};
    for(int i=n;i>=1;i--){
        a[i]=read();
    }
    vector<int> v;
    vector<int> k;
    int t2[N]={};
    for(int i=1;i<=n;i++){
        v.push_back(a[i]);
        t2[a[i]]++;
        if(t2[a[i]]>=2){
            t2[a[i]]--;
            v.pop_back();
            int x=v.back();
            while(x!=a[i]){
                if(x!=a[i])v.pop_back();
                x=v.back();
                if(x==a[i])break;
            }
        }
        k=v;
        while(!k.empty()){
            int x=k.back();
            t[x]++;
            k.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
}
