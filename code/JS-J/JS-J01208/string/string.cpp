#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stri{
    ll nu;
    char c;
}a[200005];
int main(){
    //g++ a.cpp -o a -o2 -std=c++14 
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    ll ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].nu>>a[i].c;

    }
    int l=0,r=n-1;
    while(l<r){
        if(a[l].c==a[r].c){
            if(a[l].nu==a[r].nu){
                l++;r--;

            }
            if(a[l].nu<a[r].nu){
                a[r].nu-=a[l].nu;
                l++;
            }
            if(a[l].nu>a[r].nu){
                a[l].nu-=a[r].nu;
                r--;
            }
        }
        else{
            if(a[l].nu==a[r].nu){
                ans+=a[l].nu;
                l++;r--;

            }
            if(a[l].nu<a[r].nu){
                a[r].nu-=a[l].nu;
                ans+=a[l].nu;
                l++;
            }
            if(a[l].nu>a[r].nu){
                a[l].nu-=a[r].nu;
                ans+=a[r].nu;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}