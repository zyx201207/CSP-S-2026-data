#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200100;
struct node{
    int x;
    char y;
};
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    node a[N]={};
    ll ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        cin>>a[i].y;
        ans+=a[i].x;
    }
    int l=1,r=n;
    while(l<=r){
        if(l==r){
            ans-=a[l].x;
            break;
        }
        else{
            if(a[l].x>=a[r].x){
                a[l].x-=a[r].x;
                if(a[l].y==a[r].y)ans-=2*a[r].x;
                r--;
            }
            else if(a[r].x>a[l].x){
                a[r].x-=a[l].x;
                if(a[l].y==a[r].y)ans-=2*a[l].x;
                l++;
            }
        }
    }
    cout<<ans/2;
}
