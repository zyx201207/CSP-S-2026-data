#include <bits/stdc++.h>
using namespace std;
long long a[200001]={},q[200001]={},m,n,md=0,mdi,ans=0,ly=0,t=0;
char c[200001]={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        q[i]=q[i-1]+a[i];
    }
    md=(q[n]+1)/2;
    if(md%2==0){
        t=1;
    }
    for(int i=1;i<=n;i++){
        if(md>q[i-1] and md<=q[i]){
            mdi=i;
            break;
        }
    }
    //cout<<"**"<<mdi<<" "<<md<<endl;
    long long lx=mdi-1,ls=md;
    //cout<<ls<<"//"<<endl;
    for(int i=mdi;i<=n;i++){
        ly=q[i]-md;
        long long m=md-ly+t,p=ls-m;
        //cout<<"**"<<m<<" "<<p<<endl;
        for(int j=lx;j>=1;j--){
            if(q[j]>=m){
                if(c[j]!=c[i]){
                    if(a[j]<p){
                        ans+=a[j];
                        p-=a[j];
                    }
                    else{
                        ans+=p;
                        a[j]-=p;
                    }
                }
            }
            else{
                if(q[j+1]>=m and q[j]<m){
                    lx=j+1;
                }
                else{
                    lx=j;
                }
                break;
            }
        }
        ls=m;
    }
    cout<<ans;
    return 0;
}
