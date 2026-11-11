#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
ll cnt=0;
const int maxn=1e7;
vector<char>hh;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a;
        cin>>c;
        for(int j=cnt;j<=cnt+a-1;j++){
            hh.push_back(c);
        }
        cnt+=a;
    }

    for(int i=0;i<cnt/2;i++){
        if(hh[i]!=hh[cnt-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

