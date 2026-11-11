#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans=0;
struct node{
    int sum;
    char s;
}a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        a[i].sum=x;
        a[i].s=c;
    }
    int l=1,r=n;
    while(l<r){
        if(a[l].s==a[r].s){
            if(a[l].sum>a[r].sum){
                a[l].sum-=a[r].sum;
                r--;
            } else if(a[r].sum>a[l].sum){
                a[r].sum-=a[l].sum;
                l++;
            } else {
                r--;
                l++;
            }
        } else{
            if(a[l].sum>a[r].sum){
                ans+=a[r].sum;
                a[l].sum-=a[r].sum;
                r--;
            } else if(a[r].sum>a[l].sum){
                ans+=a[l].sum;
                a[r].sum-=a[l].sum;
                l++;
            } else {
                ans+=a[r].sum;
                r--;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
