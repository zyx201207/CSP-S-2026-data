#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll L,ans;
struct str{
    int a;
    char c;
}S[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>S[i].a>>S[i].c;
        L+=S[i].a;
    }
    int iL=0,jL=0;
    for(int i=0,j=n+1;i<j;){
        if(iL==0) iL=S[++i].a;
        if(jL==0) jL=S[--j].a;
        if(i>=j) break;
        if(S[i].c!=S[j].c){
            if(iL>=jL){
                ans+=jL;
                iL-=jL;
                jL=0;
            }
            else{
                ans+=iL;
                jL-=iL;
                iL=0;
            }
        }
        else{
            if(iL>=jL){
                iL-=jL;
                jL=0;
            }
            else{
                jL-=iL;
                iL=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
