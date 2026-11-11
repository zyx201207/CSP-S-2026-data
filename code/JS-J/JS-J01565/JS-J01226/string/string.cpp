#include <bits/stdc++.h>
using namespace std;
int n,a,x,ans=0,flag=0;
string s=" ";
char b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if (n==1){
        cout<<"0";
        return 0;
    }
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        x+=a;
        if (b==s[s.size()-1])flag=1;
        else flag=0;
        for (int j=1;j<=a;j++)s+=b;
    }
    if (x==n){
        cout<<(n+1)/2;
        return 0;
    }
    if (flag){
        cout<<"0";
        return 0;
    }
    for (int i=1;i<=(x+1)/2;i++){
        if (s[i]!=s[x+1-i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
