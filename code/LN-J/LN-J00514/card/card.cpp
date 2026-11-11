

#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
string s[500005];
struct information{
    int cnt;
}in[3000005];
void solve(int x){
    string st;
    for(int i=x;i<=n;i++){
        if(in[a[i]].cnt==0){
            st+=char(a[i]+'0');
            in[a[i]].cnt++;
        }else{
            int markj;
            string ct;
            for(int j=0;j<st.length();j++){
                if(st[j]==(char(a[i]+'0'))){
                    markj=j+1;
                }
            }
            for(int j=0;j<markj;j++) ct+=st[j];
            st=ct;
        }
    }
    s[x]=st;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) in[j].cnt=0;
        solve(i);
    }
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            for(int k=0;k<s[j].length();k++){
                if(s[j][k]==char(i+'0')){
                    cnt++;
                }
            }
        }
        cout<<cnt;
        if(i!=m) cout<<" ";
    }
    return 0;
}

