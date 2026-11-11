#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,m,a[3][1000060]={};
ll check_min_length(ll aa,ll b,ll n){
    ll mmin=0;
    for(ll i=0;i<n;i++){
        if(a[0][i]==aa){
            if(a[1][i]==b){
                return n+1;
            }else{
                mmin=min(check_min_length(a[1][i],b,n+1),mmin);
            }
        }else if(a[1][i]==aa){
            if(a[0][i]==b){
                return n+1;
            }else{
                mmin=min(check_min_length(a[0][i],b,n+1),mmin);
            }
        }
    }
    return mmin;

}
void problem_solve(){
    cin>>n>>m;
    for(ll i=0;i<n-1;i++){
        cin>>a[0][i]>>a[1][i];
    }
            ll mmax=0;
    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j++){
            for(ll ij=0;ij<n;ij++){
                ll aaa=min(check_min_length(ij+1,i+1,0),check_min_length(ij+1,j+1,0));
                mmax=max(aaa,mmax);
            }
        }
    }
    cout<<mmax<<endl;
    return;
}

int main(){
    freopen("hub1.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(ll i=0;i<t;i++){
        problem_solve();
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
