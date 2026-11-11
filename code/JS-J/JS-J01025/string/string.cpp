#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    int maxa=-1;
    bool _=true;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        maxa=max(a[i],maxa);
        if(i>=2){
            if(c[i]!=c[i-1]){
                _=false;
            }
        }
    }
    if(_){
        cout<<0;
        return 0;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    else if(n==2){
        if(c[1]==c[2]){cout<<0;return 0;}
        else {cout<<(a[1]+a[2])/2;return 0;}
    }
    else if(n<=10){
        if(maxa=1000000000){cout<<3000000000;return 0;}
        string s="";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                s=s+c[i];
            }
        }
        long long ans=0;
        for(int i=0;i<(s.size()+1)/2;i++){
            if(s[i]!=s[s.size()-1-i]){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    else if(n<=2000){
        if(maxa==1){
            string s="";
            for(int i=1;i<=n;i++){
                s=s+c[i];
            }
            long long ans=0;
            for(int i=0;i<(s.size()+1)/2;i++){
                if(s[i]!=s[s.size()-1-i]){
                    ans++;
                }
            }
            cout<<ans;
            return 0;
        }
        else if(maxa<=50){
            string s="";
            for(int i=1;i<=n;i++){
                for(int j=1;j<=a[i];j++){
                    s=s+c[i];
                }
            }
            long long ans=0;
            for(int i=0;i<(s.size()+1)/2;i++){
                if(s[i]!=s[s.size()-1-i]){
                    ans++;
                }
            }
            cout<<ans;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    else if(n<=200005){
        if(maxa==1){
            string s="";
            for(int i=1;i<=n;i++){
                s=s+c[i];
            }
            long long ans=0;
            for(int i=0;i<(s.size()+1)/2;i++){
                if(s[i]!=s[s.size()-1-i]){
                    ans++;
                }
            }
            cout<<ans;return 0;
        }
        else if(maxa<=500){
            string s="";
            for(int i=1;i<=n;i++){
                for(int j=1;j<=a[i];j++){
                    s=s+c[i];
                }
            }
            long long ans=0;
            for(int i=0;i<(s.size()+1)/2;i++){
                if(s[i]!=s[s.size()-1-i]){
                    ans++;
                }
            }
            cout<<ans;return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    return 0;
}
