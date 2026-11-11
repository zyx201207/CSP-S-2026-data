#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==1){
        cout<<0;
    }else{
        string s="";
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i];j++){
                s+=c[i];
            }
        }
        int l=s.size(),ans=0;
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1]) ans++;
        }
        cout<<ans;
    }
    return 0;
}
