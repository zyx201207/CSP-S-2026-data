#include<bits/stdc++.h>
using namespace std;
long long n,mm,ans,m,a[500100];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    mm=m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        for(int j=i;j>=1;j--){
            mm=mm-a[i]+a[j];
            if(mm==0)
                if(i-j+1>ans)
                    ans=i-j+1;
            if(mm<0)
                break;
        }
        mm=m;
    }
    cout<<ans;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
long long n,mm,ans,m,a[500100];
bool check(int va){
    int ll=1,rr=n,mi;
    while(ll<=rr){
        mi=(ll+rr)>>1;
        if(a[mi]<=va)
            ll=mi+1;
        else
            rr=mi-1;
    }
    int id=ll-1;
    int sum=0;
    for(int i=id;i>=1;i--){
        sum=sum+va-a[i];
        if(sum==m)
            if(id-i+1>ans){
                ans=id-i+1;
                return true;
        }
    }
    if(sum>m)
        return false;
    else{
        if(id>ans)
            ans=id;
        return true;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    mm=m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=a[2],r=a[n],mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(!check(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}
*/
