#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int n,last,ans=0,cnt=0;
char ch[N];
struct node{
    int s;
    char id;
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].id;
        for(int j=1;j<=a[i].s;j++){
            ch[++cnt]=a[i].id;
        }
    }
    for(int i=1;i<=ceil(1.0*cnt/2);i++){
        if(ch[i]!=ch[cnt-i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
