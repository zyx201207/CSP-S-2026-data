#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll n,m,a[500005],ans=0,len=0,num=0,cnt=0;
ll fr=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);num=m;
    for(int i=1;i<=n;i++){
        num=num-(len*(a[i]-cnt));
        len++;cnt=a[i];
        while(num<0){
            fr++;len--;
            num+=cnt-a[fr];
        }
        ans=max(ans,len);
    }
    cout<<ans;
    return 0;
}
