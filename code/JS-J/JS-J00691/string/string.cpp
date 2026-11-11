#include <bits/stdc++.h>
#define int long long
using namespace std;
int num[200003],ss[200003],s[200003];
char c[200003];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,L=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>c[i];
        ss[i]=ss[i-1]+num[i];
    }
    L=ss[n];
    for(int i=1;i<=n;i++) s[i]=ss[i-1]+1;
    int lst=n,lstt=L+1,ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        int tot=num[i],it;
        for(int j=lst;j>=i;j--){
            if(tot<lstt-s[j]){
                if(c[j]!=c[i]) ans+=tot;
                lstt-=tot;
                it=j;
                break;
            }
            if(c[j]!=c[i]) ans+=lstt-s[j];
            tot-=lstt-s[j];
            lstt=s[j];
        }
        if(ss[i]>=L/2){
            cout<<ans<<'\n';
            return 0;
        }
        lst=it;
    }
    return 0;
}
/*3
2 a
2 b
1 c
*/
