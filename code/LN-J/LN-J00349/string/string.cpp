#include<bits/stdc++.h>
using namespace std;
char s[1000000007];
long long cnt,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char s1;
        cin>>a>>s1;
        while(a--){
            s[cnt]=s1;
            cnt++;
        }
    }
    for(long long i=0;i<=(cnt-1)/2;i++){
        if(s[i]!=s[cnt-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
