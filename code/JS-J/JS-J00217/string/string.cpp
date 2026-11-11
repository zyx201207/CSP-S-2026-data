#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n+5);
    vector<char> c(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int j=n,cc=0,ans=0,ccc=0;
    for(int i=1;i<j;i++){
        if(c[j]!=c[i]){
            ans+=min(a[i]-ccc,a[j]-cc);
        }
        if(a[i]-ccc==a[j]-cc){
            j--;
            cc=0;
            ccc=0;
            continue;
        }else if(a[i]-ccc>a[j]-cc){
            ccc+=a[j]-cc;
            j--;
            cc=0;
            while(a[i]-ccc>a[j] && i!=j){
                if(c[j]!=c[i]){
                    ans+=a[j];
                }
                ccc+=a[j];
                j--;
            }
            if(i==j){
                break;
            }
            if(a[i]-ccc==a[j]){
                if(c[j]!=c[i]){
                    ans+=a[j];
                }
                ccc=0;
                j--;
            }else{
                if(c[j]!=c[i]){
                    ans+=a[i]-ccc;
                }
                cc=a[i]-ccc;
                ccc=0;
            }
        }else{
            cc+=a[i]-ccc;
            a[i]=0;
        }
    }
    cout<<ans;
    //AC
    return 0;
}
