#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m=0,x=0,y,z;
int a[N],b[N];
bool d=false;
char sa[N],sb[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>sa[i];
        m+=a[i];
    }
    m=(m+1)/2;
    if(m%2)d=true;
    for(int i=1;i<=n;i++){
        if(m>a[i])m-=a[i];
        else{
            x=i;
            break;
        }
    }
    for(int i=n;i>x;i--){
        b[++y]=a[i];
        sb[y]=sa[i];
    }
    b[++y]=a[x]-m;
    a[x]=m;
    sb[y]=sa[x];
    if(d)a[x]--;
    if(a[x]==0)x--;
    if(b[y]==0)y--;
    n=1;
    m=1;
    while(n<=x&&m<=y){
        if(sa[n]!=sb[m]){
            if(a[n]>=b[m])z+=b[m];
            else z+=a[n];
        }
        if(a[n]>b[m])a[n]-=b[m++];
        else if(a[n]<b[m])b[m]-=a[n++];
        else {
            n++;
            m++;
        }
    }
    cout<<z;
    return 0;
}
