#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;

int n,m,dig[N][32];
ll a[N],sum;

void Div_t(ll x,int pos){
    int cnt=0;
    while(x){
        dig[pos][cnt]=x%2;
        x/=2;
        cnt++;
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+1+n);

    sum=a[n-m+1];
    for(int i=n-m+2;i<=n;i++){
        sum&=a[i];
    }

    cout<<sum<<"\n";


    //for(int i=1;i<=n;i++){
        //Div_t(a[i],i);
    //}


    //int st=1,ed=n;
    //for(int i=30;i>=0;i--){
        //int l=st,r=ed,ans=0;
        //while(l<=r){
            //cout<<l<<" "<<r<<"\n";
            //int mid=(l+r)>>1;
            //if(dig[mid][i]){
               // ans=mid;
                //r=mid-1;
            //}
            //else l=mid+1;
        //}

        //if(ans!=0){
            //st=ans;
            //ed=n;
        //}
        //if(ed-st==m) break;

    //}

    //sum=a[st];
    //for(int i=st+1;i<=ed;i++){
        //sum&=a[i];
    //}

    //cout<<sum<<"\n";


    return 0;
}
