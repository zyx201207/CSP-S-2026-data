#include<bits/stdc++.h>
using namespace std;
char s[1000000011];
long long n,ans=0,cnt;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    freopen("string3.in","r",stdin);
    freopen("string3.out","w",stdout);


    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        char c;
        cin>>c;
        while(x--){
            s[cnt++]=c;
        }


    }

    for(int i=0;i<(cnt+1)/2;i++){
        if(s[i]!=s[cnt-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
