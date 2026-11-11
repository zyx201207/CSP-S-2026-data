#include <bits/stdc++.h>
using namespace std;

bool flag=0;
int c,n,x;
long long d;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>x;
    for(int q=0;q<x;q++){
        long long ans=0;
        cin>>n>>d;
        vector<long long> island;
        long long a;
        for(int i=0;i<n;i++){
            cin>>a;
            island.push_back(a);
        }
        for(int i=0;i<=n-4;i++){
            int j=i+1,k=i+2,p=i+3;
            if((island[p]-island[i]>d)&&(island[k]-island[i]<=d)&&(island[p]-island[j]<=d)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
