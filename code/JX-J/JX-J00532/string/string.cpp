#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct qw{
    int a;
    char b;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    long long l=1,r=n;
    while (l<r){
        if (s[l].b==s[r].b){
            if (s[l].a>s[r].a){
                s[l].a-=s[r].a;
                r--;
            }
            else if (s[l].a==s[r].a){
                l++;
                r--;
            }
            else{
                s[r].a-=s[l].a;
                l++;
            }
        }
        else{
            ans+=min(s[l].a,s[r].a);
            if (s[l].a>s[r].a){
                s[l].a-=s[r].a;
                r--;
            }
            else if (s[l].a==s[r].a){
                l++;
                r--;
            }
            else{
                s[r].a-=s[l].a;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
