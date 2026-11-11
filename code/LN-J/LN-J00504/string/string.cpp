#include<bits/stdc++.h>
using namespace std;
string c;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    char b;
    int si,hsi;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            c+=b;
        }
    }
    si=c.size();
    hsi=si/2;
    if(si%2==0){
        int j=si-1;
        for(int i=0;i<hsi;i++){
            if(c[i]!=c[j]){
                ans++;
            }
            j--;
        }
    }
    else{
        int j=si-1;
        for(int i=0;i<hsi;i++){
            if(c[i]!=c[j]){
                ans++;
            }
            j--;
        }
    }
    cout<<ans;
    return 0;
}
