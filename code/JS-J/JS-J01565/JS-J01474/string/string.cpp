#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct node{
    ll len;
    char c;
};
node a[200005];
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
    }
    int l=1;
    int r=n;
    while(l<r){
        if(a[l].c!=a[r].c){
            if(a[l].len<a[r].len){
                ans+=a[l].len;
                a[r].len-=a[l].len;
                l++;
            }
            else{
                ans+=a[r].len;
                a[l].len-=a[r].len;
                r--;
            }
        }
        else{
            if(a[l].len<a[r].len){
                a[r].len-=a[l].len;
                l++;
            }
            else{
                a[l].len-=a[r].len;
                r--;
            }
        }
    }
    cout<<ans;
}
