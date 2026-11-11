#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    ll a[200005];
    char b[200005];
    for(int i=0;i<n;++i){
        cin >> a[i] >> b[i];
    }
    ll ans=0;int i=0;int j=n-1;
    while(i<j){
        ll tmp;
        char t;
        if(b[i]==b[j]){
            tmp=a[i]-a[j];
            a[j]-=a[i];
            a[i]=tmp;
            if(a[i]<=0)
                ++i;
            if(a[j]<=0)
                --j;

        }
        if(b[i]!=b[j]){
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                --j;
            }else if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                ++i;
            }else{
                ans+=a[j];
                ++i;
                --j;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

