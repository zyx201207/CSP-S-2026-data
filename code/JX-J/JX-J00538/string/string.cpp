#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
int n,a[N];
char c[N];
int ans,flag;
int main(){
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        flag+=a[i];
    }
    sort(c+1,c+n+1);
    if(c[1]==c[n]){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(flag%2==1){
            ans=flag/2;
        }
        else ans=1;
    }
    cout<<ans;
    return 0;
}