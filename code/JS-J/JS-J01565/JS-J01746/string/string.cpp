#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long sum;
int n,a;
char c;
string s,s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a--)
            s+=c;
    }
    s1=s.substr(0,s.size()>>1);
    s2=s.substr((s.size()>>1)+(s.size()&1?1:0),s.size()>>1);
    for(int i=0;i<(s.size()>>1);i++)
        if(s1[i]!=s2[i])
            sum++;
    printf("%lld",min(sum,(long long)(s.size())-sum));
    return 0;
}
