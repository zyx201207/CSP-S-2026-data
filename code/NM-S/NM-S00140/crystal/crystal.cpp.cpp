#include<bits/stdc++.h>
using namespace std;
int n;
long long m,cnt;
int a[100000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        for(long long j=m;j>=0;j--){
            a[i]+=a[i]+1;
            if(a[i]==a[i-1]){
                cnt++;
                continue;
            }
        }
    }
    cout<<cnt;
    return 0;
}
