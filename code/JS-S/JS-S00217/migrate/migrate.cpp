#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll n,c,t,d;
ll x[maxn];
vector<int> ei;
vector<int> e;
int check(int l,int gs){
    int r=gs-1;
    if(gs<=3){
            if(gs<=2)return 0;
        if(e[3]-e[1]<=d&&e[2]-e[0]<=d){
            return 1;
        }else{
            return 0;
        }
    }
    if(e[r]-e[r-1]>d){
        return 0;
    }
    if(e[1]-e[0]>d){
        return 0;
    }
    if(e[r]-e[r-2]>d){
        e.pop_back();
        return check(l,gs-1);
    }
    if(e[2]-e[0]>d){
        for(int i=0;i<=r-1;i++){
            e[i]=e[i+1];
        }
        e.pop_back();
        return check(l,gs-1);
    }
    if(e[r]-e[r-2]<=d){
        e[r-1]==e[r];
        e.pop_back();
        return check(l,gs-1);
    }
    if(e[2]-e[0]<=d){

        for(int i=1;i<=r-1;i++){
            e[i]=e[i+1];
        }
        e.pop_back();
        return check(l,gs-1);
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10||c>=13){
    while(t--){
            cin>>n>>d;
            ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            e.push_back(x[i]);
        }
        for(int i=1;i<=n-3;i++){
                ei.push_back(i);
            for(int j=i+3;j<=n;j++){
                ei.push_back(j);
                e=ei;
                if(x[j]-x[i]>d)
                if(check(0,i+1)){

                    ans++;
                }
                ei.pop_back();
            }
        ei.pop_back();
        }
        cout<<ans+1<<'\n';
    }
    //return 0;
    }
    if(c==11||c==12||c==0){
        while(t--){
            cin>>n>>d;
            for(ll i=1;i<+n;i++){
                cin>>x[i];
            }
            if(d>2*x[1]){
                cout<<"0"<<endl;
            }else{
                ll k=d/x[1];
                if(k==0)k++;
                ll ans=(k-1)*(n-k-1)/k+n%k;
                cout<<ans*(ans-1)/2+(ans+ans%k)*(ans/k)/2<<endl;
            }
        }
    }
    return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
