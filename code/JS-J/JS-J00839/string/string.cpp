#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
char c[1000005];
bool ishuiwen(string s){
    string t=s;
    reverse(t.begin(),t.end());
    if(s==t){
        return true;
    }
    else{
        return false;
    }
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1ll){
        cout<<0ll;
        return 0;
    }
    if(n==2ll){
        int aaaa,bbbb;
        char cccc,dddd;
        cin>>aaaa>>cccc;
        cin>>bbbb>>dddd;
        if(cccc!=dddd)
            cout<<min(aaaa,bbbb);
        else{
            cout<<0ll;
        }
        return 0;
    }
    string s="";
    int cnt=0;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
        if(c[i]!=c[i-1]&&i!=1){
            flag=false;
        }
    }
    if(flag==true){
        cout<<0;
        return 0;
    }
    if(ishuiwen(s)==true){
        cout<<0;
        return 0;
    }
    int ans=0;
    int ccnt=0;
    int cccnt=0;
    for(int i=1;i<=(cnt-1)/2+1;i++){
        if(ccnt+a[i]!=a[n-i+1]||a[i]!=cccnt+a[n-i+1]){
            if(c[i]!=c[n-i+1]){
                ans+=min(a[i],a[n-i+1]);
            }
            else{
                if(a[i]>a[n-i+1]){
                    ccnt+=abs(a[i]-a[n-i+1]);
                }
                else{
                    cccnt+=abs(a[i]-a[n-i+1]);
                }
                ans+=abs(a[i]-a[n-i+1]);
            }
        }
        else{
            if(c[i]!=c[n-i+1]){
                ans+=min(a[i],a[n-i+1]);
            }
        }
    }
    cout<<ans;
    return 0;
}
