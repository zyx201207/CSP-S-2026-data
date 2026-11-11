#include <bits/stdc++.h>

using namespace std;
long long n,a,j,ans=0,sum=0;
char c;
string s[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>c;
        for(j=0;j<a;j++){
            s[j]=c;
        }
    }
    for(int i=0;i<=j+1;i++){
        if(s[i]!=s[j-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
