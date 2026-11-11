#include<bits/stdc++.h>
using namespace std;
long long a[5000001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,mm;
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(mm==0){
        cout<<0;
        return 0;
    }
    sort(a+1,a+n+1);
    long long maxn=-2e9;
    for(int i=2;i<=n;i++){
        long long m=mm;
        int ii=i-1;
        long long sum=1;
        while(m>0&&ii>0){
            m-=a[i]-a[ii];
            ii--;
            if(m>=0){
                sum++;
            }
        }
        maxn=max(maxn,sum);
    }
    cout<<maxn;
    return 0;
}