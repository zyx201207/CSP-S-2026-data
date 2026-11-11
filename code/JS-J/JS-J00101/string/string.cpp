#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N=2e5+5;
ll n,l=1,r,t1=0,t2,ans,a[N];
char ch1,ch2,ch[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        a[i]=a[i-1]+a[i];
    }
    a[n+1]=a[n]+1;
    t2=n+1;
    r=a[n];
    while(l<=a[n]/2){
        if(l>a[t1]){
            t1++;
            ch1=ch[t1];
        }
        if(r<=a[t2-1]){
            t2--;
            ch2=ch[t2];
        }
        ch1=ch[t1];
        ch2=ch[t2];
        //cerr<<ch1<<' '<<ch2<<' '<<l<<' '<<r<<' '<<t1<<'.'<<a[t1]<<':'<<ch[t1]<<' '<<t2<<'.'<<a[t2]<<':'<<ch[t2]<<endl;
        if(ch1!=ch2)ans++;
        l++;
        r--;
        //cerr<<l<<' '<<a[n]/2;
    }
    cout<<ans;
    //cerr<<ans;
    return 0;
}
