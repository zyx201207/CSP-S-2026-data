#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
string s="#";
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int L=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        L+=a;
        for(int i=1;i<=a;i++) s.push_back(c);
    }
    int ans=0;
    for(int i=1;i<=L/2;i++){
        if(s[i]!=s[L-i+1])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
