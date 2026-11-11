#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
string s="s";
int main(){
    freopen("string.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        string a;
        cin>>x>>a;
        cnt+=x;
        while(x--){
            s+=a;
        }
    }
    for(long long i=1;i<=cnt/2;i++){
        if(s[i]!=s[cnt+1-i]){
            ans++;
        }
    }
    cout<<ans;
    freopen("string.out","w",stdout);
    return 0;
}
