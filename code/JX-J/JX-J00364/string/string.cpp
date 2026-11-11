#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
string q,q1,q2;
int a[200005];
char s[200005];
char s1[200005];
char s2[200005];
int cnt[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        while(a[i]--){
            q+=s[i];
        }
    }
    q1=q;
    reverse(q.begin(),q.end());
    q2=q;
    q=q1;
    if(q==q2){
        cout<<0;
        return 0;
    }
    ans=q.size()/2;
    cout<<ans;
    return 0;
}
