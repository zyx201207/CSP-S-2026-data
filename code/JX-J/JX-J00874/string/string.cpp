#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=2e5+10;
struct Node{
    int a;
    char c;
}s[N],d[N];
int ans=0;
string res;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int sum=0;
    int cnt=1;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    d[1].a=s[1].a;
    d[1].c=s[1].c;
    for(int i=1;i<n;i++){
        if(s[i].c==s[i+1].c){
            d[cnt].c=s[i].c;
            d[cnt].a+=s[i+1].a;
        }else if(s[i].c!=s[i+1].c){
            cnt++;
            d[cnt].c=s[i+1].c;
            d[cnt].a+=s[i+1].a;
        }
    }
    int l=1;
    int r=cnt;
    while(l<=r){
        if(d[l].c!=d[r].c){
            ans+=min(d[l].a,d[r].a);
            if(max(d[l].a,d[r].a)==d[l].a){
                d[l].a-=d[r].a;
                r--;
            }else {
                d[r].a-=d[l].a;
                l++;
            }
        }else {
            if(max(d[l].a,d[r].a)==d[l].a){
                d[l].a-=d[r].a;
                r--;
            }else {
                d[r].a-=d[l].a;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
