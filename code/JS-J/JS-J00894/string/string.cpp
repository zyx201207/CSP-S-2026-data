#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,t,ans=0;
const int N = 2e5 + 10;
struct str{
    int temp;
    char c;
}a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int num = n;
    for(int i=0;i<n;i++) cin>>a[i].temp>>a[i].c;
    int i=0,j=n-1;
    while(true){
        if(a[i].temp > a[j].temp){
            if(a[i].c != a[j].c){
                ans += a[j].temp;
                a[i].temp -= a[j].temp;
                a[j].temp = 0;
                j--;
            }
            else{
                a[i].temp -= a[j].temp;
                a[j].temp = 0;
                j--;
            }
        }
        if(a[i].temp <= a[j].temp){
            if(a[i].c != a[j].c){
                ans += a[i].temp;
                a[j].temp -= a[i].temp;
                a[i].temp = 0;
                i++;
            }
            else{
                a[j].temp -= a[i].temp;
                a[i].temp = 0;
                i++;
            }
        }
        num--;
        if(num == 1) break;
    }
    cout<<ans<<"\n";
    return 0;
}
