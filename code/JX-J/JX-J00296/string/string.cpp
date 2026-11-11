#include<bits/stdc++.h>
using namespace std;
int n,a[200005],len=0;
char c[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    int l=1,r=n;
    bool f=true;
    while(l<=r){
        if(a[l]!=a[r]||c[l]!=c[r]){
            f=false;
            break;
        }
        l++;
        r--;
    }
    if(f){
        cout<<'0';
    }else{
        int o=0,ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                s[o]=c[i];
                o++;
            }
        }
        int l=0,r=len-1;
        while(l<=r){
            if(s[l]!=s[r]){
                ans++;
            }
            l++;
            r--;
        }
        cout<<ans;
    }
    return 0;
}
