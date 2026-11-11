#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,a[N],x,y,ans;
char c[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    x=1;
    y=n;
    while(x<y){
        if(a[x]<a[y]){
            if(c[x]!=c[y]){
                ans+=a[x];
                a[y]-=a[x];
                x++;
            }
            else{
                a[y]-=a[x];
                x++;
            }
        }
        else if(a[x]==a[y]){
            if(c[x]!=c[y]){
                ans+=a[x];
                x++;
                y--;
            }
            else{
                x++;
                y--;
            }
        }
        else if(a[x]>a[y]){
            if(c[x]!=c[y]){
                ans+=a[y];
                a[x]-=a[y];
                y--;
            }
            else{
                a[x]-=a[y];
                y--;
            }
        }
    }
    cout<<ans;
    return 0;
}
