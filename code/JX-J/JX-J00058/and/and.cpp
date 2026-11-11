#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll a[n]={0};
    ll cnt=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        ll s[n]={0};
        for(ll j=0;j<n;j++){
            s[j]=a[j];
        }
        ll temp=s[0];
        s[0]=s[i];
        s[i]=temp;
        ll cnt1=s[0];
        for(ll z=1;z<m;z++){

            ll num2=cnt1&s[z];
            //cout<<num2<<endl;
            for(int f=z;f<n;f++){
                if(num2<cnt1&s[f]){
                    num2=cnt1&s[f];
                    temp=s[z];
                    s[z]=s[f];
                    s[f]=s[z];
                    //cout<<s[f]<<endl;
                }
            }
            cnt1=num2;
        }
        if(cnt1>cnt){
            cnt=cnt1;
        }
    }
    cout<<cnt;
    return 0;
}
