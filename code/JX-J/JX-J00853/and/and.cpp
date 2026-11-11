#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    long long sum=a[1];
    int p=1;
    int pos=1;
    for(int i=2;i<=n,p<m;i++){
        if(a[i]&sum==0){
            sum=a[pos+1];
            pos=pos+1;
            p=0;
            continue;
        }
        sum&=a[i];
        p++;
    }
    cout<<sum;
}
