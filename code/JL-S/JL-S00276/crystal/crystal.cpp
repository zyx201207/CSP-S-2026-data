#include<bits/stdc++.h>
using namespace std;
long long a[1000000],n,m,b[1000000];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
cin>>n>>m;
bool flag=1,llll=1;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]!=i){
        flag=0;
    }
}
if(flag){
    long long cnt=1;
    long long sum=0;
    for(int i=1;i<n;i++){
        sum+=i;
        if(sum>m){
            break;
        }
        cnt++;
    }
    cout<<cnt<<endl;
}
else{
    long long d=a[2]-a[1];
    for(int i=2;i<n;i++){
        if(a[i]+d!=a[i+1]){
            llll=0;
            break;
        }
    }
    if(llll){
        long long cnt=1;
        long long sum=0;
        for(int i=1;i<n;i++){
            sum+=i*d;
            if(sum>m){
                break;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            b[i]=abs(a[i]-a[i-1]);
        }
        sort(a+1,a+1);
        long long sum=0;
        long long cnt=0;
        for(int i=1;i<=n-1;i++){
            sum+=b[i];
            if(sum>m){
                break;
            }
            cnt++;
        }
        cout<<cnt;
    }
}
return 0;
}
