#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nod{
    int t;
    string s;
}a[1000006];
int n,sum;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].t>>a[i].s;
    }int l=1,r=n;
    int lsum=a[l].t,rsum=a[r].t;
    while(l<r){
        if(lsum>=rsum){
            lsum-=rsum;
            if(a[l].s!=a[r].s){
                sum+=rsum;
            }r--;
            rsum=a[r].t;
        }else{
            rsum-=lsum;
            if(a[l].s!=a[r].s){
                sum+=lsum;
            }l++;
            lsum=a[l].t;
        }
    }cout<<sum;
    return 0;
}

