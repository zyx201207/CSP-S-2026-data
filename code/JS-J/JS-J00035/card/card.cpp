#include<bits/stdc++.h>
using namespace std;
int a[500005],v[300005],n,m,s[500005],l[300005];
bool vi[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]]+=i;
    }
    for(int i=1;i<=n;i++){
        if(vi[a[i]]){
            for(int j=l[a[i]];j<i;j++){
                v[a[j]]--;
            }
            l[a[i]]=i;
        }
        vi[a[i]]=1;
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<' ';
    }
    return 0;
}
