#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
ll b[200005];
char c[200005];
ll num=0;
int n;
void solve_1(){
    ll ans=0;
    ll l=1,r=num,x=1,y=n;
    while(l<r&&x<y&&l<(num/2)&&r>(num/2)){
        if(c[x]==c[y]){
            if(b[x]>b[y]){
                y--;
                r-=b[y];
                b[x]-=b[y];
                l+=b[y];
            }
            else if(b[x]<b[y]){
                x++;
                l+=b[x];
                b[y]-=b[x];
                r-=b[x];
            }
            else{
                x++;
                y--;
                l+=b[x];
                r-=b[y];
            }
        }
        else{
            if(b[x]>b[y]){
                y--;
                r-=b[y];
                b[x]-=b[y];
                l+=b[y];
                ans+=b[y];


            }
            else if(b[x]<b[y]){
                x++;
                l+=b[x];
                b[y]-=b[x];
                r-=b[x];
                ans+=b[x];

            }
            else{
                x++;
                y--;
                l+=b[x];
                r-=b[y];
                ans+=b[x];
            }
        }
    }
    ans+=abs(b[y]-b[x-1]);
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        num+=a[i];
        b[i]=a[i];
    }
    if(num<=3e7){
        string s;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                s+=c[i];
            }
        }
        int ans=0;
        for(int i=0;i<=(num/2)+1;i++){
            if(s[i]!=s[num-i-1]){
                ans++;
            }
        }
        cout<<ans;
    }
    else{
        solve_1();
    }
    return 0;
}
