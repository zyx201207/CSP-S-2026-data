#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int N=2e5+5;
const int INF=1e9+5;
ull cnt;
ll n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s="";
    cin>>n;
    for(int i=0;i<n;i++){
        ll k;
        char a;
        cin>>k>>a;
        for(int i=0;i<k;i++){
            s+=a;
        }
    }
    ll l=0;
    ll r=s.length()-1;
    while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt<<endl;
    return 0;
}
