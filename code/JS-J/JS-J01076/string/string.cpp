#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,l,r,ans;
pair<int,char>stk[N];
char s[5];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&stk[i].first);
        scanf("%s",s+1);
        stk[i].second=s[1];
    }   
    l=1,r=n;
    while(l<r){
        if(stk[l].second==stk[r].second){
            int del=min(stk[l].first,stk[r].first);
            stk[l].first-=del;
            stk[r].first-=del;
            if(stk[l].first==0){
                l++;
            }
            if(stk[r].first==0){
                r--;
            }
        }else{
            int del=min(stk[l].first,stk[r].first);
            ans+=del;
            stk[l].first-=del;
            stk[r].first-=del;
            if(stk[l].first==0){
                l++;
            }
            if(stk[r].first==0){
                r--;
            }           
        }
    }
    printf("%lld\n",ans);
    return 0;
}