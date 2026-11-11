#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],ans[30005];
string s;
bool f[30005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int t=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(t-1!=n){
        s="";
        memset(f,0,30005);
         for(int i=t;i<=n;i++){
            int k=s.find(char(a[i]+48));
            if(k!=string::npos) s.erase(k,s.size()-k);
            s=s+to_string(a[i]);
            //cout<<s<<endl;
         }
        for(int i=0;i<s.size();i++){
            int p=int(s[i]-48);
            if(f[p]) continue;
            else f[p]=1,ans[p]++;
        }
        t++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}


