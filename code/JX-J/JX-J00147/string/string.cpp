#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
struct node{
    int k;
    char s;
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int l=1,r=n,sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].k>>a[i].s;
    }
    while(l<r){
        if(a[l].k==a[r].k){
            if(a[l].s!=a[r].s){
                sum+=a[l].k;
            }
            l++;r--;
        }
        else if(a[l].k>a[r].k){
            if(a[l].s!=a[r].s){
                sum+=a[r].k;
            }
            a[l].k-=a[r].k;
            r--;
        }else{
            if(a[l].s!=a[r].s){
                sum+=a[l].k;
            }
            a[r].k-=a[l].k;
            l++;
        }
    }
    cout<<sum;
    return 0;
}
