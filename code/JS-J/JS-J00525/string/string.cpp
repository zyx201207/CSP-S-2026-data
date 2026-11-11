#include<bits/stdc++.h>
using namespace std;
long long n,x1,ans;
long long a[200005];
string s1,s[200005],s2[200005],s4[200005];
bool hui(string x){
    string x1;
    for(int i=x.size();i>0;i--){
        x1+=x[i];
    }
    if(x==x1) return true;
    else return false;
}
bool b(string x){
    for(int i=1;i<=n;i++){
        if(s2[i]==x) return true;
    }
    return false;
}
string zip(string s1){
    string s3[200005];
    int x=0;
    for(int i=1;i<=n;i++){
        if(!b(s[i])){
            x++;
            s3[i]=s[i];
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(s[i]==s3[i]){
                x1+=a[i];
            }
        }
        a[i]=x1;
        s4[i]=s3[i];
    }
    for(int i=1;i<=n;i++){
        s1+=s4[i];
    }
    if(!hui(s1)){
        return zip(s1);
    }
    return s1;
}
int main(){
//    freopen("string.in","r",stdin);
//    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        s1+=s[i];
    }
    if(hui(s1)){
        cout<<ans;
        return 0;
    }
    else{
        s1=zip(s1);
        for(int i=1;i<=x1;i++){
            ans+=a[i];
        }
    }
    cout<<ans;
    return 0;
}
