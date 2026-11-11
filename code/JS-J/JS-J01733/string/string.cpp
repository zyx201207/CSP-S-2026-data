#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,sum;
string s;
int a[200005];
char b[200005];
int main(){
    freopen("string6.in","r",stdin);
    freopen("string6.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    s=' ';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    for(int i=1;i<=(sum+1)/2;i++){
        if(s[i]!=s[sum+1-i])ans++;
    }
    cout<<ans;
    return 0;
}
