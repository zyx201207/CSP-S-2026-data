#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
pair<int,char> a[200005];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        s+=a[i].first;
    }
    s=(s+1)/2;
    int k=0,x=0;
    for(int i=1;i<=n;i++){
        k+=a[i].first;
        if(k>=s){
            x=k-s;
            x=a[i].first-x;
            if(x==0)x=a[i].first;
            k=i;
            break;
        }
    }
    int l=1,r=n,sl=0,sr=0,ans=0;
    while(l<=k&&r>=k){
        if(l==k&&r==k)break;
        else if(a[l].second!=a[r].second){
            if(a[l].first>a[r].first){
                a[l].first-=a[r].first;
                sl+=a[r].first;
                sr+=a[r].first;
                ans+=a[r].first;
                r--;
            }
            else if(a[l].first<a[r].first){
                a[r].first-=a[l].first;
                sl+=a[l].first;
                sr+=a[l].first;
                ans+=a[l].first;
                l++;
            }
            else{
                sl+=a[r].first;
                sr+=a[r].first;
                ans+=a[l].first;
                l++;
                r--;
            }
        }
        else if(a[l].second==a[r].second){
            if(a[l].first>a[r].first){
                sl+=a[r].first;
                sr+=a[r].first;
                a[l].first-=a[r].first;
                r--;
            }
            else if(a[l].first<a[r].first){
                sl+=a[l].first;
                sr+=a[l].first;
                a[r].first-=a[l].first;
                l++;
            }
            else{
                sl+=a[r].first;
                sr+=a[r].first;
                l++;
                r--;
            }
        }
    }

    cout<<ans;
    return 0;
}
