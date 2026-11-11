#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
///////////// I want to 4/5*AC.
    int n;
    cin>>n;
    string s;
    long long sum=0;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];++j){
            s+=c[i];
        }
    }
    string t=s;
    reverse(t.begin(),t.end());
    if(t==s){
        cout<<0<<"\n";
    }else{
        int ans=0;
        int len=s.size()-1;
        int l=0,r=len;
        while(l<r){
            if(s[l]!=s[r]){
                ++ans;
            }if(l+1<r-1&&s[l+1]!=s[r-1]){
                ++ans;
            }if(l+2<r-2&&s[l+2]!=s[r-2]){
                ++ans;
            }if(l+3<r-3&&s[l+3]!=s[r-3]){
                ++ans;
            }if(l+4<r-4&&s[l+4]!=s[r-4]){
                ++ans;
            }if(l+5<r-5&&s[l+5]!=s[r-5]){
                ++ans;
            }if(l+6<r-6&&s[l+6]!=s[r-6]){
                ++ans;
            }if(l+7<r-7&&s[l+7]!=s[r-7]){
                ++ans;
            }if(l+8<r-8&&s[l+8]!=s[r-8]){
                ++ans;
            }if(l+9<r-9&&s[l+9]!=s[r-9]){
                ++ans;
            }
            l+=10;
            r-=10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
