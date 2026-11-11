#include<bits/stdc++.h>
using namespace std;

string c;long long n,a,ans=0;string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    int tmp=0;
    if(s.size()%2==0)tmp=-1;
    for(int i=s.size()/2;i<=s.size();i++){
        if(s[i-2*(i-s.size()/2)+tmp]!=s[i])ans++;
    }
    cout<<ans;
}
