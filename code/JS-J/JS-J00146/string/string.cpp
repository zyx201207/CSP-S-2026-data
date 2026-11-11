#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;

struct zf{
    int a;
    char c;
}s[200005];
signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
        cin>>s[i].c;
    }


    bool is=true;
    for(int i=2;i<=n;i++){
        if(s[i].c!=s[i-1].c)is=false;
    }
    if(is){
        cout<<0;
        return 0;
    }

    int ans=0;
    for(int i=1,j=n;i<=j;){
        if(i==j){
            if(s[i].a%2==0)ans++;
            break;
        }
        if(s[i].a<s[j].a){
            if(s[i].c!=s[j].c){
                ans+=s[i].a;
                s[j].a-=s[i].a;
                i++;
            }else{
                ans+=s[j].a-s[i].a;
                s[j].a-=s[i].a;
                i++;
            }
        }else if(s[i].a==s[j].a){
            if(s[i].c!=s[j].c){
                ans+=s[i].a;
                i++;
                j--;
            }else{
                i++;
                j--;
            }
        }else{
            if(s[i].c!=s[j].c){
                ans+=s[j].a;
                s[i].a-=s[j].a;
                j--;
            }else{
                ans+=s[i].a-s[j].a;
                s[i].a-=s[j].a;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
