#include<bits/stdc++.h>
using namespace std;
int n;
long long zlen;
long long a[200005];
char c[200005];
string s=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        zlen+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long zhong=floor(1.0*zlen/2),num=a[1];
    long long ans=0;
    for(int i=1;i<=zhong;i++){
        if(s[i]!=s[zlen-i+1])
            ans++;
    }
    cout<<ans;
    return 0;
}
