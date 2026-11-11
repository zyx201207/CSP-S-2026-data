#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
ll s[N];
char t[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    ll i=1,j=n,ret=0;
    while(i<j){
        if(s[i]==s[j]){
            ret+=t[i]==t[j]?0:s[i];
            i++,j--;
        }
        else if(s[i]<s[j]){
            ret+=t[i]==t[j]?0:s[i];
            s[j]-=s[i];
            i++;
        }
        else{
            ret+=t[i]==t[j]?0:s[j];
            s[i]-=s[j];
            j--;
        }
    }
    cout<<ret;
    return 0;
}
