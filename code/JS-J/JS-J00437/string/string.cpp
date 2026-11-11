#include<bits/stdc++.h>
using namespace std;
int n,ans;
string S;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int x;
    char cx;
    for(int i=1;i<=n;i++){
        cin>>x>>cx;
        for(int j=1;j<=x;j++) S+=cx;
    }
    int siz=S.size();
    for(int i=0;i<siz/2;i++){
        if(S[i]!=S[siz-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
