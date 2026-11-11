#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,cnt;
string ans;
struct st{
    int n;
    char a;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].n>>s[i].a;
        sum+=s[i].n;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s[i].n;j++){
            ans+=s[i].a;
        }
    }
    for(int i=0;i<=sum/2-1;i++){
        if(ans[i]!=ans[sum-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
