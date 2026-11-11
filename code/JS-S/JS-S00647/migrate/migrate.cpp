#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+5;
int num[N];
signed main(){
    freopen("migrate4.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,T;
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        int f=1;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            if(i>=3 && (num[i]-num[i-1]!=num[i-1]-num[i-2])){
                f=0;
            }
        }
        if(n<4){
            cout<<0<<"\n";
            continue;
        }
        if(f){
            int base =num[2]-num[1];
            if(num[4]-num[1]>d || d<base){
                cout<<0<<"\n";
            }
            else{
                int cnt=d/base;
                int sum=n-((n-1)/cnt)-cnt;
                cout<<sum<<"\n";
            }
        }
        //for(int i=1)
    }
    return 0;
}
