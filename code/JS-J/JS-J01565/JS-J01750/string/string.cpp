#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        long long k;
        string l;
        cin>>k;
        cin>>l;
        for(int long long i=0;i<k;i++){
            a+=l;
        }
    }
    b=a;
    reverse(a.begin(),a.end());
    for(long long i=0;i<n;i++){
        if(a[i]!=b[i]) ans++;
    }
    cout<<ans;
    return 0;
}
