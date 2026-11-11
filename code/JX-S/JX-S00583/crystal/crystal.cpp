#include<bits/stdc++.h>
using namespace std;
int n,p[220];
long long m,a[514514],ans,b[220],k,s[514514];
bool f;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            long long c=1,s=0;
            for(int j=i-1;j;j--){
                if(s+(a[i]-a[j])>m) break;
                s+=(a[i]-a[j]);
                c++;
            }
            ans=max(ans,c);
        }
        cout<<ans;
        return 0;
    }
    /*
    for(int i=1;i<=n;i++){
        if(i!=1&&i!=n&&a[i]-a[i-1]!=a[i+1]-a[i]){f=1;break;}
    }
    if(a[1]>=-100&&a[n]<=100){
        for(int i=1;i<=n;i++) p[a[i]+101]++;
        for(int i=1;i<=a[n]+101;i++){
            if(p[i]) b[++k]=i-101;
        }
        for(int i=1;i<=k;i++){
            long long c=p[b[i]+101],s=0;
            for(int j=i-1;j;j--){
                if(s+(b[i]-b[j])>m) break;
                long long w=min(1LL*p[b[j]+101],(m-s)/(b[i]-b[j]));
                s+=((b[i]-b[j])*w);
                c+=w;
            }
            ans=max(ans,c);
        }
        cout<<ans;
        return 0;
    }
    if(!f){
        long long s=0,d=a[2]-a[1];
        ans=1;
        for(int i=1;i<=n;i++){
            if(s+i*d>m) break;
            s+=(i*d);ans++;
        }
        cout<<ans;
        return 0;
    }
    */
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=n;i;i--){
        if(i<ans) break;
        long long c=1,l=1,r=i;
        while(l<=r){
            long long mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) c=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-c+1);
    }
    cout<<ans;
    return 0;
}
//Don't forget to upload!!!!!
//Don't forget to freopen!!!!
//Don't forget to ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); !!!
//Don't forget long long
//Don't forget 2e5 or 5e5
