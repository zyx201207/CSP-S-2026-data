#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200001][32],tj[32];
bool numvis[200001];
int n,k;
void f(int w){
    for(int i=1;i<=n;i++){
        if(numvis[i]){
            continue;
        }
        if(a[i][w]!=1){
            for(int j=1;j<=31;j++){
                if(a[i][j]==1){
                    tj[j]--;
                }
            }
            numvis[i]=true;
        }
    }
}
int p(int n){
    ll res=1;
    for(int i=1;i<=n;i++){
        res=res*2;
    }
    return res;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    cin>>k;
    
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int p=31;
        while(x!=0){
            a[i][p]=x%2;
            tj[p]+=x%2;
            x=x/2;
            p--;
        }
    }
    ll ans=0;
    for(int i=1;i<=31;i++){
        if(tj[i]>=k){
            f(i);
            ans+=p(31-i);
        }
    }
    cout<<ans;
    return 0;
}