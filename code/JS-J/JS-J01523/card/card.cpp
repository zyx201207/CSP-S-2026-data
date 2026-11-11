#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
vector<long long>b;
long long ans[300005],v[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b.clear();
        for(int j=1;j<=m;j++)
            v[j]=0;
        for(int j=i;j<=n;j++){
            if(v[a[j]]==0){
                b.push_back(a[j]);
                v[a[j]]=1;
            }
            else{
                while(b.back()!=a[j] && !b.empty()){
                    v[b.back()]=0;
                    b.pop_back();
                }
            }
        }
        for(long long j=0;j<b.size();j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
