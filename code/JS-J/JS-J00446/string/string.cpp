#include<bits/stdc++.h>
using namespace std;
struct node{
    int cnt;
    char c;
};
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="",t="";
    int n;
    cin>>n;
    vector<node> a(n+1);
    long long w=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt>>a[i].c;
        w+=a[i].cnt;
    }
    if(w==n){
        string tmp="";
        for(int i=1;i<=n;i++){
            tmp+=a[i].c;
        }
        int ans=0;
        int len=tmp.size();
        for(int i=0;i<len/2;i++){
            if(tmp[i]!=tmp[len-i-1]){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    int w1=w/2;
    for(int i=1;i<=n;i++){
        if(w1>=a[i].cnt){
            s=s+string(a[i].cnt,a[i].c);
            w1-=a[i].cnt;
        }
        else{
            s=s+string(w1,a[i].c);
            break;
        }
    }
    w1=w/2;
    for(int i=n;i>=1;i--){
        if(w1>=a[i].cnt){
            t=t+string(a[i].cnt,a[i].c);
            w1-=a[i].cnt;
        }
        else{
            t=t+string(w1,a[i].c);
            break;
        }
    }
    w1=w/2;
    long long ans=0;
    for(int i=0;i<w1;i++){
        if(s[i]!=t[i]){
            ans=ans+1;
        }
    }
    cout<<ans;
    return 0;
}
