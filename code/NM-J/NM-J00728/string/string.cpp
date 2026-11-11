#include<bits/stdc++.h>
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
using namespace std;
long long s[1000000];
char a[1000000];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>a[i];
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=n;j++){
            if(a[i]!=a[j]){
                cnt+=min(s[i],s[j]);
                continue;
            }
            else if(s[i]!=s[j]){
                cnt+=max(s[i],s[j])-min(s[i],s[j]);
                continue;
            }

        }
    }
    if(cnt==0) cout<<0;
    else cout<<cnt/2;

    return 0;
}
