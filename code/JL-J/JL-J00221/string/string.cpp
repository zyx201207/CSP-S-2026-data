#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int a[N];
char c[N];
int ans=0;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    //cout<<s<<endl<<endl;
    for(int i=0;i<s.size();i++){
        if(i>(s.size()-1)>>1) break;
        if(s[i]!=s[s.size()-1-i]){
            ans++;
            s[s.size()-1-i]=s[i];
            //cout<<i<<" "<<s.size()-1-i<<endl;
        }
        //cout<<s[i]<<" "<<i<<"     11     "<<s[s.size()-1-i]<<" "<<s.size()-1-i<<endl;
    }
    //cout<<endl;
    cout<<ans;
    return 0;
}
/*

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
