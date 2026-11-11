#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N];
int n,m,tmp,k,ans;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        k=0;
        while(tmp>0){
            s[i]+=tmp%2+'0';
            tmp/=2;
        }
    }
    sort(s+1,s+n+1);
    for(int i=31;i>=1;i--){
        int cnt=1;
        for(int j=n;j>=1;j--){
            if(s[i][j]=='1') cnt++;
        }
        if(cnt>=m){
            int g=0;
            int wq=1;
            for(int j=0;j<s[i].size();j++){
                g+=(s[n][j]-'0')*wq;
                wq*=2;
            }
            ans=g;
            for(int j=1;j<m;j++){
                g=0,wq=1;
                for(int k=0;k<s[i].size();k++){
                    g+=(s[n-j][k]-'0')*wq;
                    wq*=2;
                }
                ans&=g;
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}
