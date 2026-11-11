#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=5e5+5;
ll n,m,a[_];
ll x,l,r,_m,cnt1,cnt2,ans,cn;
vector<ll> b;
int main(){
    freopen("crystal.in","r",stdin);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    freopen("crystal.out","w",stdout);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(n==1){
        cin>>x;
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x+=a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]&&a[i]!=a[i+1]){
            b.push_back(i);
        }
    }
    x/=n;
    r=lower_bound(a+1,a+1+n,x)-a;
    l=r-1;
    _m=0;
    while(l>=1||r<=n){
        if(abs(x-a[l])<=abs(x-a[r])&&l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt1++;
        }
        else if(abs(x-a[l])>=abs(x-a[r])&&r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt1++;
        }
        else if(l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt1++;
        }
        else if(r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt1++;
        }
        else if(_m+abs(x-a[l])>m&&_m+abs(x-a[r])>m){
            break;
        }
    }

    x++;
    r=lower_bound(a+1,a+1+n,x)-a;
    l=r-1;
    _m=0;
    while(l>=1||r<=n){
        if(abs(x-a[l])<=abs(x-a[r])&&l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt2++;
        }
        else if(abs(x-a[l])>=abs(x-a[r])&&r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt2++;
        }
        else if(l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt2++;
        }
        else if(r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt2++;
        }
        else if(_m+abs(x-a[l])>m&&_m+abs(x-a[r])>m){
            break;
        }
    }
    ans=max(cnt1,cnt2);

    for(auto u:b){
        x=a[u];
        r=lower_bound(a+1,a+1+n,x)-a;
        l=r-1;
        _m=0;
        cn=0;
        while(l>=1||r<=n){
            if(abs(x-a[l])<=abs(x-a[r])&&l>=1&&_m+abs(x-a[l])<=m){
                _m+=abs(x-a[l]);
                l--;
                cn++;
            }
            else if(abs(x-a[l])>=abs(x-a[r])&&r<=n&&_m+abs(x-a[r])<=m){
                _m+=abs(x-a[r]);
                r++;
                cn++;
            }
            else if(l>=1&&_m+abs(x-a[l])<=m){
                _m+=abs(x-a[l]);
                l--;
                cn++;
            }
            else if(r<=n&&_m+abs(x-a[r])<=m){
                _m+=abs(x-a[r]);
                r++;
                cn++;
            }
            else if(_m+abs(x-a[l])>m&&_m+abs(x-a[r])>m){
                break;
            }
        }
        ans=max(ans,cn);
    }

    x=a[n/2];
    r=lower_bound(a+1,a+1+n,x)-a;
    l=r-1;
    _m=0;
    cn=0;
    while(l>=1||r<=n){
        if(abs(x-a[l])<=abs(x-a[r])&&l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt2++;
        }
        else if(abs(x-a[l])>=abs(x-a[r])&&r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt2++;
        }
        else if(l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt2++;
        }
        else if(r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt2++;
        }
        else if(_m+abs(x-a[l])>m&&_m+abs(x-a[r])>m){
            break;
        }
    }
    ans=max(ans,cn);

    x=a[n/2+1];
    r=lower_bound(a+1,a+1+n,x)-a;
    l=r-1;
    _m=0;
    cn=0;
    while(l>=1||r<=n){
        if(abs(x-a[l])<=abs(x-a[r])&&l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt2++;
        }
        else if(abs(x-a[l])>=abs(x-a[r])&&r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt2++;
        }
        else if(l>=1&&_m+abs(x-a[l])<=m){
            _m+=abs(x-a[l]);
            l--;
            cnt2++;
        }
        else if(r<=n&&_m+abs(x-a[r])<=m){
            _m+=abs(x-a[r]);
            r++;
            cnt2++;
        }
        else if(_m+abs(x-a[l])>m&&_m+abs(x-a[r])>m){
            break;
        }
    }
    ans=max(ans,cn);
    if(ans==0){
        cout<<1;
    }
    else{
        cout<<ans;
    }
    return 0;
}
