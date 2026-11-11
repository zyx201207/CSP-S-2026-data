#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int nums;
int choose;
ll num[200000+125];

int bin1cnt(ll a){
    if(a==0)return 0;
    int res=0;
    while(a){
        res+=(a&1ll);
        a>>=1;
    }
    return res;
}

bool comp(ll a,ll b){
    return bin1cnt(a)>=bin1cnt(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>nums>>choose;
    for(int i=0;i<nums;i++){
        cin>>num[i];
    }
    sort(num,num+nums,comp);
    int res=num[0];
    for(int i=1;i<choose;i++){
        res&=num[i];
    }
    cout<<res;
    return 0;
}
