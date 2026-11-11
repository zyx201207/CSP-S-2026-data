#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,a[N];
char ch[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    ll j=n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        while(a[i]&&j>i){
            if(a[i]<=a[j]){
                if(ch[i]!=ch[j])ans+=a[i];
                a[j]-=a[i];
                a[i]=0;
                //break;
            }else{
                if(ch[i]!=ch[j])ans+=a[j];
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
        }
    }
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    cout<<ans;
    return 0;
}
