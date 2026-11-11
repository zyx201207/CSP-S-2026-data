#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct aaa{
    ll b;
    char c;
};
aaa a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].b>>a[i].c;
    }
    ll ans=0;
    for(int i=1,j=n;;){
        if(j-i==1){
            ans+=min(a[i].b,a[j].b);
            break;
        }else if(a[i].b>a[j].b){
            if(a[i].c!=a[j].c){
                ans+=a[j].b;
                a[i].b-=a[j].b;
                j--;
            }else{
                a[i].b-=a[j].b;
                j--;
            }
        }else if(a[i].b==a[j].b){
            if(a[i].c!=a[j].c){
                ans+=a[j].b;
                a[i].b=a[j].b=0;
                i++;
                j--;
            }else{
                a[i].b=a[j].b=0;
                i++;
                j--;
            }
        }else{
             if(a[i].c!=a[j].c){
                ans+=a[i].b;
                a[j].b-=a[i].b;
                i++;
            }else{
                a[j].b-=a[i].b;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
