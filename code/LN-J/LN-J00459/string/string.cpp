#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,ans;char o;string p;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
            cin>>m>>o;
            m1+=m;
            while(m--)p+=o;
    }
    for(int i=1;i<m1/2+1;i++){
        o=p[i-1];
        if(o!=p[m1-i])ans++;
    }
    cout<<ans;
    return 0;
}
