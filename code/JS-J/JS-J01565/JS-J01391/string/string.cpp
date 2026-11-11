#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct str{
    int num;
    char ch;
};
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    str a[n];
    for(int i=0;i<n;i++){
        int t1;char t2;
        cin>>t1>>t2;
        a[i].num=t1;a[i].ch=t2;
    }
    int l=0,r=n-1;
    int ans=0;
    while(l<=r){
        if(a[l].ch==a[r].ch){
            if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                r--;
            }
            else if(a[l].num<a[r].num){
                a[r].num-=a[l].num;
                l++;
            }
            else if(a[l].num==a[r].num){
                l++;r--;
            }
        }
        else{
            if(a[l].num>a[r].num){
                ans+=a[r].num;
                a[l].num-=a[r].num;
                r--;
            }
            else if(a[l].num<a[r].num){
                ans+=a[l].num;
                a[r].num-=a[l].num;
                l++;
            }
            else if(a[l].num==a[r].num){
                ans+=a[l].num;
                l++;r--;
            }
        }
    }
    cout<<ans;
    return 0;
}