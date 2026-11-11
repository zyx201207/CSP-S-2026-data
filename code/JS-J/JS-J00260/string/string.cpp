#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    string s;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++) s+=c;
    }
    ll i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) ans++;
        i++;j--;
    }
    cout<<ans<<endl;
    return 0;
}
