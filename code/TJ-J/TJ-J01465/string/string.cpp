#include<IOSTREAM>
#include<CMATH>
#include<algorithm>
using namespace std;
struct node{
    int num;
    char key;
}a[200005];
long long ad[200005],st[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].key;
        ad[i]=ad[i-1]+a[i].num;
        st[i]=ad[i-1]+1;
    }
    long long fl1=ceil(ad[n]/2.0),fl2=ceil(ad[n]/2.0),add=0;
    if(fl2%2==1) fl1--,fl2++;
    else fl2++;
    while(fl2<ad[n]+1&&fl1>0){
        long long p=lower_bound(st+1,st+n+1,fl1)-st-1;
        long long q=upper_bound(ad+1,ad+n+1,fl2)-ad-1;;
        if(ad[p]>fl1) p--;
        if(ad[q]<fl2) q++;
        if(fl1-st[p]>=ad[q]-fl2){
            if(a[p].key!=a[q].key) add+=(ad[q]-fl2+1);
            fl1-=(ad[q]-fl2+1),fl2=ad[q]+1;
        }else{
            if(a[p].key!=a[q].key) add+=(fl1-st[p]+1);
            fl1=st[p]-1,fl2+=(fl1-st[p]+1);
        }
    }
    cout<<add;
    return 0;
    //lzr
}