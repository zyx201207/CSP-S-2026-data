#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAXN=2e5+5;
ll n;
ll a[MAXN],al[MAXN],ar[MAXN];
ll pre[MAXN],prel[MAXN],prer[MAXN];
char c[MAXN],cl[MAXN],cr[MAXN];
ll lenl,lenr,plenl,plenr;
ll midp,midsum;
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll sum=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        pre[i]=pre[i-1]+a[i];
	}
    midsum=sum/2;

	ll l=1,r=n,mid=l+(r-l)/2;
	while(l<r){
        mid=l+(r-l)/2;
        if(pre[mid]<sum/2){
            l=mid+1;
        }
        else if(pre[mid]>sum/2){
            r=mid;
        }
        else{
            midp=mid;
            break;
        }
        midp=mid;
	}

    for(ll i=1;i<=midp;i++){
        al[i]=a[i];
        cl[i]=c[i];
        prel[i]=prel[i-1]+al[i];
    }
    if(pre[midp]<midsum){
        al[midp+1]=midsum-pre[midp];
        cl[midp+1]=c[midp+1];
        prel[midp+1]=prel[midp]+al[midp+1];
        lenl=prel[midp+1];
    }
    else lenl=prel[midp];

    for(ll i=n;i>=(midp+2);i--){
        ar[n-i+1]=a[i];
        cr[n-i+1]=c[i];
        prer[n-i+1]=prer[n-i]+ar[n-i+1];
    }
    if(pre[midp+1]>midsum){
        ar[n-midp]=pre[midp+1]-midsum;
        cr[n-midp]=c[midp+1];
        prer[n-midp]=prer[n-midp-1]+ar[n-midp];
        lenr=prer[n-midp];
        if(lenr>lenl){
            ar[n-midp]--;
            prer[n-mid]--;
            lenr--;
        }
    }
    else lenr=prer[n-midp-1];

    ll sp=0,pl=1,pr=1;
    while(sp<lenl){

        bool step;
        if(al[pl]!=0&&ar[pr]!=0){
            step=(prel[pl]<=prer[pr]);
        }
        else{
            step=(al[pl]==0?prer[pr]:prel[pl]);
        }

        if(cl[pl]!=cr[pr]){
            ans+=((step?prel[pl]:prer[pr])-sp);
        }
        sp=(step?prel[pl]:prer[pr]);
        if(step){
            pl++;
        }
        else{
            pr++;
        }
    }

    cout<<ans;

	return 0;
}
