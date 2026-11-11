#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5005;
long long a[N];
//bu kai long long jian zuzong
void way1(){
    long long x=n;
    long long cha;
    long long tmp1;
    cin>>tmp1;
    long long tmp2;
    cin>>tmp2;
    cha=abs(tmp1-tmp2);
    x-=2;
    while(x--){
        int tmp;
        cin>>tmp;
    }
    long long ans=1;
    long long cnt=0;

    while(cnt<=m){
        cnt+=ans*cha;
        ans++;

    }
    cout<<ans-1;

}//13-18 test point

void way2(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;

    for(int k=2;k<=n;k++){
        int cnt=0,tmp=0;
        for(int j=k;j>=1;j--){
            if(cnt+a[k]-a[j]<=m){
                cnt+=a[k]-a[j];
                tmp++;
            }else{
                break;
            }
        }
        ans=max(ans,tmp);

    }
    cout<<ans;
}//1-5 test point
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    if(n>5000){
        way1();
    }else{
        way2();
    }

    return 0;
}
// rp+++++++++++++++++++++++
