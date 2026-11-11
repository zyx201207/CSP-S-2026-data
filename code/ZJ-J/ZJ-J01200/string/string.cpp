#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
string str; int len;
void solve(){
    int n; cin>>n;
    if(n==1) cout<<0;
    else if(n==2){
        int n1,n2; char c1,c2;
        cin>>n1>>c1>>n2>>c2;
        len=n1+n2;
        for(int i=0;i<n1;i++) str+=c1;
        for(int i=0;i<n2;i++) str+=c2;
        for(int i=0;i<len;i++) cout<<str[i];
        int mid=len/2,ans=0;
        if((len)%2==0){ for(int i=0;i<mid;i++)
            if(str[mid-i-1]!=str[mid+i]) ans++;
        }else{ for(int i=0;i<mid-1;i++)
            if(str[mid-i-1]!=str[mid+i+1]) ans++;
        } cout<<min(ans,min(n1,n2));
    }else{
        for(int i=0;i<n;i++){
            int m; char c; cin>>m>>c; len+=m;
            for(int i=0;i<m;i++) str+=c;
        } int mid=len/2,ans=0;
        if((len)%2==0){ for(int i=0;i<mid;i++)
            if(str[mid-i-1]!=str[mid+i]) ans++;
        }else{ for(int i=0;i<mid-1;i++)
            if(str[mid-i-1]!=str[mid+i+1]) ans++;
        } cout<<ans;
    }
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T=1; /*cin>>T;*/
    while(T--) solve();
    return 0;
}