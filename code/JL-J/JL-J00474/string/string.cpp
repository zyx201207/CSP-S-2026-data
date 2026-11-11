#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
long long cnt;
string s,rs,c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        rs=rs+s[i];
    }
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]!=rs[i]){
            cnt++;
            s[i+1]=s[i];
            rs[i+1]=s[i+1];
        }
    }
    cout<<cnt;
    return 0;
}

