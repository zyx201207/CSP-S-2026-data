#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
long long a;
char c;
char s[N];
long long ans=0;
long long cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int k=1;k<=n;k++){
        cin>>a>>c;
        for(int i=ans;i<ans+a;i++){
            s[i]=c;
        }
        ans+=a;
    }
    for(int i=0;i<ans/2;i++){
        if(s[i]!=s[ans-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}