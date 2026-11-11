#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans=0;
struct po{
    long long a;
    char c;
};
po s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    l=1;
    r=n;
    while(l<r){
        if(s[l].c==s[r].c){
            if(s[l].a>s[r].a){
                s[l].a-=s[r].a;
                r--;
            }else if(s[l].a<s[r].a){
                s[r].a-=s[l].a;
                l++;
            }else{
                l++;
                r--;
            }
        }else{
            if(s[l].a>s[r].a){
                ans+=min(s[l].a,s[r].a);
                s[l].a-=s[r].a;
                r--;
            }else if(s[l].a<s[r].a){
                ans+=min(s[r].a,s[l].a);
                s[r].a-=s[l].a;
                l++;
            }else{
                ans+=s[l].a;
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
