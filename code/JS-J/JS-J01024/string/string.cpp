#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long x[N],len,ans;
char y[N];
string s=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        len+=x[i];
        for(int j=1;j<=x[i];j++)s+=y[i];
    }
    //cout<<s<<endl;
    for(int i=1;i<=len/2;i++){
        if(s[i]!=s[len-i+1])ans++;
    }
    cout<<ans;
    return 0;
}
