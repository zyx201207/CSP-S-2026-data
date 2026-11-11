#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long len,ans,id;
struct ST{
    long long h,t;
    char k;
}a[N];
bool cmp(ST x,ST y){
    return x.h<y.h;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch;
        long long ai;
        cin>>ai>>ch;
        a[i].h=len+1;a[i].t=len+ai;a[i].k=ch;
        len+=ai;
    }
    for(int i=1;i<=n;i++){
        if(a[i].h<=len/2&&a[i].t>=len/2){
            id=i;n++;
            a[n].h=len/2;
            a[n].t=a[i].t;a[i].t=len/2;
            a[n].k=a[i].k;
            sort(a+1,a+1+n,cmp);
            break;
        }
    }
    long long key=0;
    for(int i=1,j=n;i<=id;){
        if(a[i].k!=a[j].k){
            ans+=min(a[i].t,len-a[j].h+1)-key;
        }
        key=min(a[i].t,len-a[j].h+1);
        if(a[i].t<len-a[j].h+1)i++;
        else if(a[i].t==len-a[j].h+1)i++,j--;
        else j--;
    }
    cout<<ans;
    return 0;
}