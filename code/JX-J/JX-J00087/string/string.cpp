#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long len;
struct name{
    int n;
    char c;
}a[N];
long long s[N];
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		int t;
		char c;
        cin>>t>>c;
        a[i]={t,c};
        s[i]=a[i].n+s[i-1];
    }
       int l=1,r=n;
    long long h=s[n]/2;;
    while(l<r){
        int mid=(r-l)/2+l;
        if(s[mid]<h)l=mid+1;
        else r=mid-1;
    }
    int f=h-a[l+1];
    int u=s[l+1]-f-(s[n]%2);
    a[l+1]=0;
    int e=abs(f-u);
    if(f>u)a[l+2]-=e;
    else a[l]-=e;
    ans+=e;
    r=l+2;
    h=l;
    while(l>=1&&r<=n){
        bool fl=1;
        if(a[l].t<0){
            fl=0;
            a[l-1]+=a[l];
            if(a[--l].c!=a[h].c)ans+=a[l].t;
        }
        if(a[r].t<0){
            fl=0;
            a[r+1]+=a[r];
            if(a[++r].c!=a[h].c)ans+=a[r].t;
        }
        if(fl){
            if(a[l].t>=a[r]){
                if(a[l].c!=a[r].c)ans+=a[r].t;
                a[l].t-=a[r].t;
                r++;
            }
            else if(a[l].t<=a[r]){
                if(a[l].c!=a[r].c)ans+=a[l].t;
                a[r].t-=a[l].t;
                r++;
            }
        }
    }
    cout<<ans;
    return 0;
}
