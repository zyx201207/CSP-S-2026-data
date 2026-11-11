#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mid,ans;
ll a[500005],x[500005];

bool cmp(const ll x,const ll y){
    return abs(mid-x) < abs(mid-y); 
}

int main() {
    assert(freopen("crystal.in","r",stdin));
    assert(freopen("crystal.out","w",stdout));

    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    if(n%2==1){
        mid=a[(n+1)/2];
        sort(a+1,a+n+1,cmp);
        
        ll sum=0;
        for(int i=1;i<=n;i++){
            sum+=abs(mid-a[i]);
            if(sum>m){
                break;
            }
            ans++;
        }
    }
    else{
        mid=a[n/2];
        for(int i=1;i<=n;i++){
            x[i]=a[i];
        }

        sort(x+1,x+n+1,cmp);
         
        ll sum=0;
        ll cnt1=0,cnt2=0;

        for(int i=1;i<=n;i++){
            sum+=abs(mid-x[i]);
            if(sum>m){
                break;
            }
            cnt1++;
        }

        mid=a[(n/2)+1];
        for(int i=1;i<=n;i++){
            x[i]=a[i];
        }

        sort(x+1,x+n+1,cmp);

        sum=0;
        for(int i=1;i<=n;i++){
            sum+=abs(mid-x[i]);
            if(sum>m){
                break;
            }
            cnt2++;
        }

        ans=max(cnt1,cnt2);
    }

    cout<<ans<<endl;
    return 0;
}