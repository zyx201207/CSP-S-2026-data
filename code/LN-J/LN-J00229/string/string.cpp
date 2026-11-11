#include<bits/stdc++.h>
using namespace std;
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,now=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int j=now;j<now+x;j++)s[j]=c;
        now+=x;
    }
    int cnt=0;
    for(int i=0;i<now;i++){
        if(s[i]!=s[now-1-i])cnt++;
    }
    cout<<cnt/2;
    return 0;
}
