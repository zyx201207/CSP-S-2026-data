#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int num=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        num+=a[i];
    }
    int flag=0;
    char b=c[1];
    for(int i=1;i<=n;i++){
        if(c[i]!=b){
            flag++;
        }
    }
    if(flag==0){
        cout<<0<<endl;
        return 0;
    }
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int ans=0;
    int l=0,r=num-1;
    while(l<r){
        if(s[l]!=s[r]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
