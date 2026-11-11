#include <iostream>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;++i){
        int a;
        char c;
        cin>>a>>c;
        s.append(a,c);
    }
    long long ans=0;
    long long len=s.length();
    for(int i=1;i<=len;++i){
        if(s[i]!=s[len-i-1]){
            s[i]=s[len-i-1];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
