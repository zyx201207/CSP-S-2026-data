#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,t;
int n,d;
int x[2000006]={};

vector<int>pth;
set<int> spth;




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;

    for(int q=1;q<=t;q++){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];

        if(c==11||c==12||c==0){
            int nd=x[2]-x[1];

            cout<<max(0,n-(d/nd*2-1))<<endl;

        }


    }


}