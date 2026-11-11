#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct node{
    ll a;
    char c;
}s[200010];
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
        cin>>s[i].c;
    }
    for(int i=1,j=n;i<j;){
        if(s[i].c==s[j].c){
            if(s[i].a<s[j].a){
                s[j].a-=s[i].a;
                i++;
            }
            else if(s[i].a>s[j].a){
                s[i].a-=s[j].a;
                j--;
            }
            else {
                i++;
                j--;
            }
        }
        else {
            if(s[i].a<s[j].a){
                ans+=s[i].a;
                s[j].a-=s[i].a;
                i++;
            }
            else if(s[i].a>s[j].a){
                ans+=s[j].a;
                s[i].a-=s[j].a;
                j--;
            }
            else {
                ans+=s[i].a;
                i++;
                j--;
            }
        }
    }
    cout<<ans<<"\n";
return 0;
}
