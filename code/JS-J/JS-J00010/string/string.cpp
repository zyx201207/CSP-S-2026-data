#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,char> pi;
ll n,sum,cnt;
pi a[200020];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    std::ios::sync_with_stdio();
    std::cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        sum+=a[i].first;
    }
    int l=0,r=n-1;
    while(l<r){
        if(a[l].second==a[r].second){
            ll mn=min(a[l].first,a[r].first);
            a[l].first-=mn;
            if(a[l].first==0){
                l++;
            }
            a[r].first-=mn;
            if(a[r].first==0){
                r--;
            }
        }
        else{
            ll mn=min(a[l].first,a[r].first);
            cnt+=mn;
            a[l].first-=mn;
            if(a[l].first==0){
                l++;
            }
            a[r].first-=mn;
            if(a[r].first==0){
                r--;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
