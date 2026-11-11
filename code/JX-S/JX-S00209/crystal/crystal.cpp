#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
long long m;
long long a[N],b[N];
long long ans=0;
int num=0;
void f(int x){
    for(int i=n;i>x;i--){
            b[i]+=a[i]-a[x];
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    while(n--){
    int j=1;
    j++;
    for(int i=2;i<=n;i++){
    b[i]=a[i]-a[j];
    }
    for(int i=2;i<=n;i++)
        f(i);
    for(int i=2;i<=n;i++){
        if(b[i]<=m){
            ans=max(b[i],ans);
            num=max(i,num);
        }
    }
    for(int i=1;i<=n;i++)
        b[i]=0;
}
    cout<<num;
    return 0;
}
