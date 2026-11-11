#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL n,sum=0,ans=0;
    bool f=true;
    cin>>n;
    for(int i=0;i<n;i++){
        LL a;
        char c;
        cin>>a>>c;
        sum+=a;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    for(int i=0;i<sum/2;i++){
        for(int j=sum-i-1;j>(sum-1)/2;){
            if(s[i]!=s[j]){
                f=false;
                break;
            }
            break;
        }
    }
    if(f==true){
        ans=0;
    }
    else{
        for(int i=0;i<sum/2;i++){
            for(int j=sum-i-1;j>(sum-1)/2;){
                if(s[i]!=s[j]){
                    ans++;
                }
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
