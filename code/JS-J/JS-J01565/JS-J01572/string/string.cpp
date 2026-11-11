#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct root{
    int aa;
    char bb;
}a[200100];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].aa>>a[i].bb;
    }
    int i=1,j=n;
    while(true){
        if(i==j||i<1||j>n){
            break;
        }
        if(a[i].bb!=a[j].bb){
            if(a[i].aa>a[j].aa){
                a[i].aa-=a[j].aa;
                ans+=a[j].aa;
                j--;
            }
            else if(a[j].aa>a[i].aa){
                a[j].aa-=a[i].aa;
                ans+=a[i].aa;
                i++;
            }
            else{
                ans+=a[i].aa;
                a[i].aa=0;
                a[j].aa=0;
                i++;
                j--;
                if(i>j){
                    break;
                }
            }
        }
        else{
            if(a[i].aa>a[j].aa){
                a[i].aa-=a[j].aa;
                j--;
            }
            else if(a[i].aa<a[j].aa){
                a[j].aa-=a[i].aa;
                i++;
            }
            else{
                i++;
                j--;
                if(i>j){
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
