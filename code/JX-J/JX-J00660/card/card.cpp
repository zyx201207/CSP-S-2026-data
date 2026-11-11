#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
int n,m,v[N],a[N];
int main(){
    IOS;
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        string s;
        for(int j=i;j<=n;j++){
            int x;
            int xxx=s.length();
            for(x=0;x<xxx-1;x++){
                if(s[x]-'0'==a[j]){
                    s.erase(x,xxx);
                    break;
                }
            }
            s+=(a[j]+'0');
        }
        for(int j=0;j<s.length();j++){
            v[s[j]-'0']++;
        }
    }
    for(int i=1;i<=m;i++)cout<<v[i]<<" ";
    return 0;
}
