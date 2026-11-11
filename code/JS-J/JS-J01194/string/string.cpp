#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(2e5+10) 
int n;
long long ans=0,len[MAXN];
char c[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(len[l]>len[r]){
            len[l]-=len[r];
            if(c[l]!=c[r]) ans+=len[r];
            r--;
        }else if(len[l]<len[r]){
            len[r]-=len[l];
            if(c[l]!=c[r]) ans+=len[l];
            l++;
        }else{
            if(c[l]!=c[r]) ans+=len[r];
            l++,r--;
        }
    }cout<<ans<<"\n";
}