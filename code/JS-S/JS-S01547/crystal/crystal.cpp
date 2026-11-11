#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,m,ans=0;
    int a[MAXN]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    while(m>0){
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]) i++;
            while(m>0 && a[i]!=a[i+1]){
                a[i]++;
                m--;
            }
            break;
        }
    }


    int yangli,shuju;
    for(int i=0;i<n;i++){
        yangli=a[i];
        shuju=0;
        for(int j=0;j<n;j++){
            if(yangli==a[j]) shuju++;
        }
        if(shuju>ans) ans=shuju;
    }
    cout<<ans<<endl;
    return 0;
}
