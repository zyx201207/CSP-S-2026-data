#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int,char> a[500000];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0ll;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    int p1=1,p2=n;
    while(p1<p2){
        if(a[p1].second!=a[p2].second)cnt+=min(a[p1].first,a[p2].first);
        if(a[p1].first<a[p2].first){
            a[p2].first-=a[p1].first;
            p1++;
        }
        else if(a[p1].first>a[p2].first){
            a[p1].first-=a[p2].first;
            p2--;
        }
        else{
            p1++;
            p2--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

