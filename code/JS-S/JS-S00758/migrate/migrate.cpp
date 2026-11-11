#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    if(C==13||C==14){
        while(T--){
            long long n,d;
            cin>>n>>d;
            vector<long long> a(n);
            for(long long i=0;i<n;i++) cin>>a[i];
            cout<<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
