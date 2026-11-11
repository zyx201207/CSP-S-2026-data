#include<bits/stdc++.h>
using namespace std;
bool vis[201];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,cnt=0;
    long long l=0,ans=0;
    scanf("%d",&n);
    while(n--){
        int a;
        char c;
        cin>>a>>c;
        if (vis[c]!=true){
            vis[c]=true;
            cnt++;
        }
        l+=a;
        for (int j=1;j<=a;j++)
            s+=c;
    }
    if (cnt==1){
        cout<<0;
        return 0;
    }
    for (long long i=0;i<l/2;i++)
        if(s[i]!=s[l-i-1])
            ans++;
    cout<<ans;
    return 0;
}
