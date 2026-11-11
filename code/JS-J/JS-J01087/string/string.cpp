#include<bits/stdc++.h>
using namespace std;
long long n,s,ans;
long long a[200010];
char b[200010];
string qwe;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        s+=a[i];
        for(int j=1;j<=a[i];j++){
            qwe+=b[i];
        }
    }
    s-=2;
    for(int i=0;i<=s/2;i++){
        if(qwe[i]!=qwe[s+1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
