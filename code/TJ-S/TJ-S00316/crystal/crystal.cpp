#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n;
long long m;
long long a[N];
long long qzh[N];
int ans;

bool check(int ll,int rr){
    if(ll==rr){
        return true;
    }
    long long he=qzh[rr-1]-qzh[ll-1];
    long long xuyk=a[rr]*(rr-ll);
    long long ia=xuyk-he;
    //cout<<"ch "<<ll<<" "<<rr<<" "<<he<<" "<<xuyk<<" "<<ia<<"\n";
    if(ia<=m){
        return true;
    }
    return false;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    qzh[0]=0;
    qzh[1]=a[1];
    for(int i=2;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    /*
    cout<<n<<" "<<m<<"\n";
    cout<<"a: ";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\nqzh: ";
    for(int i=0;i<=n;i++){
        cout<<qzh[i]<<" ";
    }
    cout<<"\n";
    */
    int l=1;
    int r=1;
    ans=0;
    //int in;
    while(l<=r&&r<=n){
        if(check(l,r)){
            ans=max(ans,(r-l+1));
            //cout<<"yes"<<l<<" "<<r<<" "<<ans<<"\n";
        }
        while((!check(l,r+1))&&(l<r)&&(r<=n)){
            l++;
        }
        //cout<<l<<" "<<r<<" "<<ans<<"\n";
        if(!check(l,r+1)){
            l++;
        }
        r++;
        //cout<<l<<" "<<r<<" "<<ans<<"\n";
        //cin>>in;
    }
    cout<<ans;
    return 0;
}
