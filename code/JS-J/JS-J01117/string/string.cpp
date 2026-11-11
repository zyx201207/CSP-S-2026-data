#include <bits/stdc++.h>
using namespace std;
long long a,b[100001];
string c[100001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a;
    for(int i=1;i<=a;i++)cin>>b[i]>>c[i];
    int n=1,m=a;
    long long ans=0;
    while(n<m){
        long long x=b[n],y=b[m];
        if(c[n]!=c[m])ans+=min(x,y);
        if(x>y)b[n]-=b[m];m--;
        if(x<y)b[m]-=b[n];n++;
        if(x==y) m--;n++;
    }
    cout<<ans<<endl;
    return 0;
}
