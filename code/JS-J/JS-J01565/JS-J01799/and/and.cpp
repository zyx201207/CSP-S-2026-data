#include <bits/stdc++.h>
using namespace std;
long sj[200005],maxsz=-1;
bool cmp1(long a,long b){
    return a>=b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>sj[i];
        if(sj[i]>maxsz)
            maxsz=sj[i];
    }
    int maxsw=-1,iw=1,dx;
    for(long i=1;i<=maxsz;i*=2,iw++){
        int gs=0;
        for(int j=0;j<n;j++){
            if(sj[j]/i%2)
                gs++;
        }
        if(gs>=m){
            maxsw=iw;
            dx=i*2;
        }
    }
    for(int i=0;i<n;i++)
        sj[i]=sj[i]%dx;
    sort(sj,sj+n,cmp1);
    long zdz=0;
    dx/=2;
    for(;dx>0;dx/=2){
        int gs=0;
        for(int i=0;i<m;i++){
            if(sj[i]/dx%2)
                gs++;
        }
        if(gs==m)
            zdz++;
        zdz*=2;
    }
    cout<<zdz/2<<endl;
    return 0;
}
