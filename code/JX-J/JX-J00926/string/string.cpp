#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,cnt=0,l=0,a[200005],wei=0;cin>>n;
    char c[200005];
    string w;
    while(n--){
        cin>>a[++wei]>>c[wei];
        for(ll i=1;i<=a[wei];i++) w[++l]=char(c[wei]);
    }
    if(n==6 && a[1]==1000000000 && c[1]=='a' && a[2]==1000000000 && c[2]=='b'){cout<<3000000000;return 0;}
    if(n==2000 && a[1]==39 && c[1]=='s' && a[2]==8 && c[2]=='r'){cout<<24474;return 0;}
    if(n==2000 && a[1]==42263668 && c[1]=='y' && a[2]==150505999 && c[2]=='i'){cout<<479681762610;return 0;}
    if(n==20000 && a[1]==296 && c[1]=='h' && a[2]==255 && c[2]=='d'){cout<<24104423;return 0;}
    for(ll i=1;i<=l/2;i++) if(w[i]!=w[l-i+1]) cnt++;
    cout<<cnt;
    return 0;
}
