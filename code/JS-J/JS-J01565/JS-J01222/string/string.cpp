#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a[200005];
int b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>a[i];
    }
    for(int i=1,j=n;i<=j;){
        if(a[i]==a[j]){
            if(b[i]==b[j]){
                i++;
                j--;
            }
            else if(b[i]>b[j]){
                b[i]-=b[j];
                j--;
            }
            else{
                b[j]-=b[i];
                i++;
            }
        }
        else{
            if(b[i]==b[j]){
                ans+=b[i];
                i++;
                j--;
                //cout<<ans<<'\n';
            }
            else if(b[i]>b[j]){
                b[i]-=b[j];
                ans+=b[j];
                j--;
                //cout<<ans<<'\n';
            }
            else{
                b[j]-=b[i];
                ans+=b[i];
                i++;
                //cout<<ans<<'\n';
            }
        }
    }
    cout<<ans;
    return 0;
}