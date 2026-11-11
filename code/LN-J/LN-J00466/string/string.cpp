#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,sum=0;
    cin>>n;
    cout<<n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    string s;
    int p=0,q=0;
    bool flag=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s.push_back(c[i]);
            cnt++;
            if(cnt==sum/2&&sum%2==0){
                flag=true;
                p=i;
                q=j;
                break;
            }else if(cnt==sum/2+1&&sum%2==1){
                flag=true;
                p=i;
                q=j;

                break;
            }
        }
        if(flag){
            break;
        }
    }
    int k=0,ans=0;
    string a1=s;
    reverse(a1.begin(),a1.end());
     for(int i=p;i<=n;i++){
        if(i==p){
            for(int j=(q+1);j<=a[i];j++){
                if(c[i]!=a1[k]){
                    ans++;
                }
                k++;
            }
        }
        for(int j=1;j<=a[i];j++){
            if(c[i]!=a1[k]){
                ans++;
            }
            k++;
        }
     }
     cout<<ans;
    return 0;
}
