#include<bits/stdc++.h>
using namespace std;
long long n,m;
int l[200001];
bool k[200001];
int ans;
void q(int a){
    if(a==0){
        int p=0;
        for(int i=1;i<=n;i++){
            if(k[i]==1){
                if(p==0) p=l[i];
                else p&=l[i];
            }
        }
        ans=max(ans,p);
    }
    for(int i=1;i<=n;i++){
        if(k[i]==0){
            k[i]=1;
            q(a-1);
            k[i]=0;
        }
    }
}
string b;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        maxn++;
        l[maxn]=v;
    }
    q(m);
    cout<<ans;
    return 0;
}


