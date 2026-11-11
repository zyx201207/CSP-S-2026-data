#include<bits/stdc++.h>
#define int long long
struct str{
    int m;
    char s;
};
str stri[200005];
int n,len,middle,l=1,r=0,ans;
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>stri[i].m>>stri[i].s;
    }
    r=n;
    while(l<r){
        if(stri[l].s!=stri[r].s){
            if(stri[l].m>stri[r].m){
                ans+=stri[r].m;
                stri[l].m-=stri[r].m;
                stri[r].m=0;
                r-=1;
            }
            else if(stri[l].m==stri[r].m){
                ans+=stri[l].m;
                r-=1;
                l+=1;
            }
            else{
                ans+=stri[l].m;
                stri[r].m-=stri[l].m;
                stri[l].m=0;
                l+=1;
            }
        }
        else{
            if(stri[l].m>stri[r].m){
                stri[l].m-=stri[r].m;
                stri[r].m=0;
                r-=1;
            }
            else if(stri[l].m==stri[r].m){
                r-=1;
                l+=1;
            }
            else{
                stri[r].m-=stri[l].m;
                stri[l].m=0;
                l+=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
