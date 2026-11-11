#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=500050;

ll n,m;
ll a[N];
ll dif[N];
ll cf[N];
bool is_spe=true;
bool flag;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        cf[i]=a[i]-a[i-1];
    }

    for(int i=3;i<=n;i++){
        if(cf[i]!=cf[i-1]){
            is_spe=false;
            break;
        }
    }

    if(is_spe){
        ll df=cf[2];
        // cout<<df<<"\n";
        for(int i=1;i<=n;i++){
            dif[i]=(df+(i-1)*df)*(i-1)/2;
        }
        // cout<<dif[n]<<"\n";
        for(int i=n;i>=1;i--){
            if(dif[i]<=m){
                cout<<i<<"\n";
                // cout<<"special!"<<"\n";
                flag=true;
                return 0;
            }
        }
        if(!flag)cout<<"0"<<"\n";

        return 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            dif[i]+=a[i]-a[j];
        }
    }

    for(int i=n;i>=1;i--){
        if(dif[i]<=m){
            flag=true;
            cout<<i<<"\n";
            break;
        }
    }

    if(!flag){
        cout<<"0"<<"\n";
    }

    return 0;
}