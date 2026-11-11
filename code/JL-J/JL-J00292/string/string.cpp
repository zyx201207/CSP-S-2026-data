#include<bits/stdc++.h>
using namespace std;
int n,a[300000];
long long ans=0;
string s[300000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        if(i!=1&&s[i]!=s[i-1]) f=false;
    }
    if(f==true){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<min(a[1],a[2]);
        return 0;
    }
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            if(s[i]!=s[n-i+1]){
                for(int j=0;j<max(a[i],a[n-i+1]);j++){
                    string s1=s[i],s2=s[n-i+1];
                    if(s1[j]!=s2[max(a[i],a[n-i+1])-j+1]) ans++;
                }
            }
        }
    }else{
        for(int i=1;i<=(n-1)/2;i++){
            if(s[i]!=s[n-i+1]){
                for(int j=0;j<max(a[i],a[n-i+1]);j++){
                    string s1=s[i],s2=s[n-i+1];
                    if(s1[j]!=s2[max(a[i],a[n-i+1])-j+1]) ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
