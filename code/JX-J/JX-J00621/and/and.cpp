#include <bits/stdc++.h>
using namespace std;
long long a[101101];
string c,b;
long long sum;
int p;
string d;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==2){
        while(a[n]!=0){
            c[p]=a[n]%2-'0';
            p++;
            a[n]=a[n]/2;
        }p=0;
        while(a[n-1]!=0){
            b[p]=a[n-1]%2-'0';
            p++;
            a[n]=a[n-1]/2;
        }
        int u=c.size();
        int uu=b.size();
        for(int i=1;i<=max(u,uu);i++){
                if(c[i]==b[i] && c[i]=='1'){
                    d[i]=1;
                }
        }
        int oo=1;
        for(int i=0;i<max(u,uu);i++){
            oo*=2;
            sum+=oo*(d[i]-'0');
        }cout<<sum;
    }
    return 0;
}
