#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
vector<long long> b(500005,-1);
vector<long long> c(300005,-1);
vector<long long> d(300005,0);
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=c[a[i]];
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int l=n;
        while(l>=i){
            if(b[l]!=-1){
                if(b[l]>=i){
                    l=b[l];
                    continue;
                }
            }
            d[a[l]]++;
            l--;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i];
        if(i!=m) cout<<' ';
    }
    return 0;
}
