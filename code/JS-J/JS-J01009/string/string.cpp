#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s[200005];
ll n;
ll num[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>num[i]>>s[i];
    }
    ll ans=0;
    for(ll i=1,j=n;i<=j;){
        if(s[i]==s[j]){
            if(num[i]<num[j]){
                num[j]-=num[i];
                num[i]=0;
                i++;
            }
            else if(num[i]==num[j]){
                num[i]=0;
                num[j]=0;
                i++;
                j--;
            }
            else{
                num[i]-=num[j];
                num[j]=0;
                j--;
            }
        }
        else{
            if(num[i]<num[j]){
                ans+=num[i];
                num[j]-=num[i];
                num[i]=0;
                i++;
            }
            else if(num[i]==num[j]){
                ans+=num[i];
                num[i]=0;
                num[j]=0;
                i++;
                j--;
            }
            else{
                ans+=num[j];
                num[i]-=num[j];
                num[j]=0;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;

}
