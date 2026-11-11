#include<bits/stdc++.h>
using namespace std;
char c[200001];
int n,ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    cin>>n;
    int w=1;
    for(int i=1;i<=n;i++){
        int k;char d;
        cin>>k>>d;
        while(k--){
            c[w]=d;
            w++;
        }
    }
    w--;
    for(int i=1;i<=w/2;i++)
        if(c[i]!=c[w+1-i])
            ans++;
    cout<<ans;
    return 0;
}
