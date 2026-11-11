#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int s[2000005][2];
LL ans;
int l,r;
int x;
char c;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        s[i][0]=x;
        s[i][1]=c;
    }
    l=1,r=n;
    while(l<r){



            if(s[l][0]>s[r][0]){
                s[l][0]-=s[r][0];
                 if(s[l][1]!=s[r][1]){
                    ans+=s[r][0];
                 }
                s[r][0]=0;

                r--;
            }else if(s[l][0]<s[r][0]){
                s[r][0]-=s[l][0];
                if(s[l][1]!=s[r][1]){
                    ans+=s[l][0];
                 }
                s[l][0]=0;
                l++;
            }else{
                  if(s[l][1]!=s[r][1]){
                    ans+=s[l][0];
                 }
                 s[l][0]=s[r][0]=0;
                r--,l++;
            }



    }
   // ans+=s[l][0];
    //ans+=s[r][0];
    cout<<ans;
    return 0;
}
