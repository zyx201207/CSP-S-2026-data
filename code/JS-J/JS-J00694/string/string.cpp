#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e5+10;
struct p
{
    ll num;
    char ch;
}a[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        cin>>a[i].ch;
    }

    ll cnt=0;
    //2 a
    //2 b
    //1 c

    //1 a
    //2 b

    //1 b
    ll i=1,j=n;
    while(i<=j){
        if(i==j) break;
        int l=min(a[i].num,a[j].num);
        if(a[i].ch!=a[j].ch)
        {
            cnt+=l;
            if(a[i].num==a[j].num)
            {
                i++;
                j--;
            }
            else if(a[i].num<a[j].num)
            {
                i++;
                a[j].num-=l;
            }else
            {
                j--;
                a[i].num-=l;
            }
        }else
        {
            if(a[i].num==a[j].num)
            {
                i++;
                j--;
            }
            else if(a[i].num<a[j].num)
            {
                i++;
                a[j].num-=l;
            }else
            {
                j--;
                a[i].num-=l;
            }
        }
    }

    cout<<cnt;

    /*ll n;
    string s;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        char c;
        cin>>c;
        for(ll i=1;i<=x;i++){
            s+=c;
        }
    }

    ll cnt=0;
    for(ll i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j]) cnt++;
    }
    cout<<cnt;*/

    return 0;
}
