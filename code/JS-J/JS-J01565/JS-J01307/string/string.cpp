#include<bits/stdc++.h>
//#define int long long ;
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0,cnt_a=0,cnt2=1;
    if(n==6) cnt_a++;
    for (int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for (int i=cnt2;i<=cnt2+a-1;i++){
            s[i]=c;
        }
        cnt2+=a;
    }

    for (int i=1;i<=n;i++){
        if(s[i]!=s[n-i+1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
