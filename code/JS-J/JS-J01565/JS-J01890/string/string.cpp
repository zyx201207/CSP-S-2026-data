#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,len=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        char c;
        scanf("%d",&a);
        cin>>c;
        len+=a;
        while(a--) s.push_back(c);
    }
    for(int i=0;i<len-i-1;i++) if(s[i]!=s[len-i-1]) ans++;
    printf("%d",ans);
    return 0;
}
