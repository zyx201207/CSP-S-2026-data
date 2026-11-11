#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int sum=-1;
    for(int i=1;i<=n;i++){
        long long s=m;
        int cnt=0;
        for(int j=n-i+1;j>=1;j--){
            if(s-(a[n-i+1]-a[j])>=0){
                s-=a[n-i+1]-a[j];
                cnt++;
            }
            if(cnt>sum) sum=cnt;
        }
    }
    cout<<sum;
    return 0;
}
