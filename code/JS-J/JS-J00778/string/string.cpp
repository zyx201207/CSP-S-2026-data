#include<bits/stdc++.h>
using namespace std;
int n,x,s,ans,a[6000000];
char ch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>ch;
        for(int j=1;j<=x;j++){
            a[++s]=ch;
        }
    }
    for(int i=1;i<=s;i++){
        if(a[i]!=a[s+1-i]){
               if(i>=(s+1-i)){
                cout<<ans<<endl;
                return 0;
            }
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
