#include<bits/stdc++.h>
using namespace std;
pair<int,char> a[200005];
int n;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    int l=1,r=n;
    while(l<r){
        if(a[l].second!=a[r].second)ans+=min(a[l].first,a[r].first);
        if(a[l].first>=a[r].first){
            a[l].first-=a[r].first;
            a[r].first=0;
            r--;
        }
        else{
            a[r].first-=a[l].first;
            a[l].first=0;
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
