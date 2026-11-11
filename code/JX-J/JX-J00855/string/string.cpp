#include<bits/stdc++.h>
using namespace std;
int n;
int s[100005];
char a[100005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>a[i];
    }
    int ll=1;
    int rr=n;
    int w=0;
    while(ll<rr){
        if(a[rr]==a[ll]){
            if(s[rr]<=s[ll]){
                s[ll]-=s[rr];
                s[rr]=0;
                rr--;
            }
            else if(s[rr]>s[ll]){
                s[rr]-=s[ll];
                s[ll]=0;
                ll++;
            }
        }
        else{
            if(s[rr]<=s[ll]){
                ans+=s[rr];
                s[ll]-=s[rr];
                s[rr]=0;
                rr--;
            }
            else if(s[rr]>s[ll]){
                ans+=s[ll];
                s[rr]-=s[ll];
                s[ll]=0;
                ll++;
            }
        }
    }
    cout<<ans;
    return 0;
}
