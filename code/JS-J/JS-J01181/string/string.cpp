#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a[N],ans=0;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    long long d=0,f=a[j];
    char s='0',t=c[j--];
    while(i<=j){
        while(i<=j&&d<=f){
            if(c[i]!=t){
                ans+=min(f-d,a[i]);
            }
            d+=a[i];
            s=c[i++];
        }
        while(i<=j&&d>f){
            if(c[j]!=s){
                ans+=min(d-f,a[j]);
            }
            f+=a[j];
            t=c[j--];
        }
    }
    cout<<ans;
    return 0;
}
