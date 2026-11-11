#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
struct node{
    long long a;
    char c;
}s[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    long long ans;
    int l=1,r=n;
    while(l<=r){
        if(s[l].a<s[r].a){
            if(s[l].c!=s[r].c){
                ans+=s[l].a;
            }
            s[r].a-=s[l].a;
            l++;
        }else if(s[l].a>s[r].a){
            if(s[l].c!=s[r].c){
                ans+=s[r].a;
            }
            s[l].a-=s[r].a;
            r--;
        }else{
            if(s[l].c!=s[r].c){
                ans+=s[r].a;
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
