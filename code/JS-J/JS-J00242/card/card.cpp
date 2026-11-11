#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N];
int cnt[N];
struct qu{
    int s[N];
    int be=0,en=0;
    void p(int x){
        s[en++]=x;
    }
    void c(){
        be=en-1;
    }
    void c2(){
        be=en=0;
        a[be]=0;
    }
    int t(){
        return s[be];
    }
}q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        q.c2();
        for(int j=i;j<=n;j++){
            q.p(a[j]);
            if(q.t()==a[j]){
                q.c();
            }
        }
        for(int j=q.be;j<q.en;j++){
            cnt[q.s[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
