#include<bits/stdc++.h>
#define int long long
#define ft first
#define sd second
using namespace std;
pair<int,char> a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].ft>>a[i].sd;
    }
    int l = 1,r = n,ans = 0;
    while(n > 1){
        if(a[l].ft > a[r].ft){
            if(a[l].sd == a[r].sd){
                a[l].ft-=a[r].ft;
                r--;
                n--;
            }
            else{
                a[l].ft-= a[r].ft;
                ans+=a[r].ft;
                r--;
                n--;
            }
        }
        else if(a[l].ft < a[r].ft){
            if(a[l].sd == a[r].sd){
                a[r].ft-=a[l].ft;
                l++;
                n--;
            }
            else{
                a[r].ft-=a[l].ft;
                ans+=a[l].ft;
                l++;
                n--;
            }
        }
        else{
            if(a[l].sd == a[r].sd){
                l++;
                r--;
                n-=2;
            }
            else{
                ans+=a[l].ft;
                l++;
                r--;
                n-=2;
            }
        }
    }
    cout<<ans;
    return 0;
}
//9:03 kai xie
//9:06 xie wan di yi ban
//9:10 di yi ban zhi jie tong guo!
