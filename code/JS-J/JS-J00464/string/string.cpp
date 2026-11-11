#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[200005];
    long long k=0;
    char c[200005];
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        k+=a[i];
    }
    long long num=0,tl=0,tr=0,i=1,j=1,xiao,da,pan=1;
    long long m=k/2;
    tl+=a[i];
    tr+=a[n+1-j];
    while(tl<=m||tr<=m){
        if(tl>tr){
            xiao=tr;
            da=tl;
            pan=1;
        }
        else{
            xiao=tl;
            da=tr;
            pan=0;
        }
        if(c[i]!=c[n+1-j])
        {
            num+=xiao;
            if(i==1&&j==1){
                num+=0;
            }
            else{
                if(pan==1){
                    num+=a[n+1-j];
                    if(i!=1)
                        num-=da;
                }
                else{
                    num+=a[i];
                    if(j!=1)
                        num-=da;
                }
            }
        }
        if(tl>tr){
            j++;
            tr+=a[n+1-j];
        }
        if(tr>tl){
            i++;
            tl+=a[i];
        }
        if(tr==tl){
            i++;
            j++;
            tr+=a[n+1-j];
            tl+=a[i];
        }
    }
    cout<<num<<endl;
    return 0;
}
