#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
            cout<<c[i]<<endl;
        }
    }
    long long ans=0;
    for(int i=0;i<=(s.length()-1)/2;i++){
        if(s[i]!=s[s.length()-i-1])ans++;
    }
    cout<<ans;
return 0;
}
