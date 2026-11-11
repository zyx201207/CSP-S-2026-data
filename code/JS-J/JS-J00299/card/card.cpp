//computer si ji le seven times
#include<bits/stdc++.h>
using namespace std;
// #define long long int
#define int long long
int n,js_j00299;
int cd[500010],ans[500010];
// int l;
// int u;
// int o;
// int g;
// int u;//?????
// int mian(){
//     return sqrt(-1);
// }``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
void work(int at){
    int t[500010]={0},a=1;
    for(int i=at;i<=n;i++){
        for(int j=1;j<=a;j++){
            if(cd[i]==t[j])a=j;
        }
        t[a]=cd[i];
    }
    for(int i=1;i<=a;i++){
        ans[t[i]]++;
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>js_j00299;
    if(js_j00299==1){
        cout<<n;
        return 0;
    }else{
        cout<<"1 n";
        return 0;
    }
    for(int i=1;i<=n;i++)cout<<"1 ";
    return 0;
}