#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long int ans=0,sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int p;
        char q;
        cin>>p>>q;
        for(int i=1;i<=p;i++){
            s[++sum]=q;
        }
    }
    for(long long int i=1;i<=sum/2;i++){
        if(s[i]!=s[sum-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}
