#include<bits/stdc++.h>
using namespace std;
char a[2000010];
int cnt=1,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        while(x--){
            a[cnt++]=c;
        }
    }
    cnt--;
    for(int i=1;i<=cnt/2;i++){
        if(a[i]!=a[cnt-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
