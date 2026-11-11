#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll cards[500005],sum[300005];
vector<ll>table;
ll judge(vector<ll> x,ll y){
    //cout<<"judgeing"<<y<<endl;
    for(ll j=0;j<x.size();j++){
        //cout<<"##judge:"<<x[j]<<endl;
        if(x[j]==y){
            //cout<<"find at"<<j<<endl;
            return j;
        }
    }return -1;
}
void GameSimulate(int step){
    //cout<<"Round:"<<step<<endl;
    table.clear();
    for(ll i=step;i<=n;i++){
        //cout<<"Now put:"<<cards[i]<<endl;
        ll posfind=judge(table,cards[i]);
        if(posfind==-1){
            //cout<<"Normal"<<endl;
            table.push_back(cards[i]);
        }else{
            //cout<<"already have,popppping";
            for(int j=1;j<=table.size()-posfind;j++){
                table.pop_back();
                //cout<<"pop"<<endl;
            }
        }
    }for(ll arr:table){
        //cout<<"Table Remain:"<<arr<<endl;
        sum[arr]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>cards[i];
    }for(ll i=1;i<=n;i++){
        GameSimulate(i);
    }for(ll i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
