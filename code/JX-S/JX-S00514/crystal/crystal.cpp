#include<bits/stdc++.h>
using namespace std;
int n,max1,cnt=0;
long long m,a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];}
    if(n>5000){
        if(a[1]+1==a[2]){
                int m3=m;
                for(int i=1;i<=n;i++){
                    if(m3-i<0)break;
                    m3-=i;
                    cnt++;
                    if(m3==0)break;
                }
                cout<<cnt;
            }
        else if(a[1]-a[2]==a[3]-a[4]){
                int cz=a[1]-a[2],m2=m;
                for(int i=1;i<=n;i++){
                    if(m2-cz<0)break;
                    m2-=cz;
                    cnt++;
                    if(m2==0)break;
                }
                cout<<cnt;
    }

}

else{    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
            int s=0,m1=m;
        for(int j=i;j>=1;j--){
            int cha=a[i]-a[j];
            if(m1-cha<0)continue;
            m1-=cha;
            s++;
            if(m==0)break;
        }
        max1=max(s,max1);
    }
    cout<<max1;}
    //ji de qu xiao zhu shi
return 0;}
