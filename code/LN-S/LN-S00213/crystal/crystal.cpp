#include <bits/stdc++.h>

using namespace std;
 long long n,m,a[500005],b[500005],max01,cnt=0;
int main()
{
    int A=1,B=1;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
if(A!=0&&a[i]!=i){
    A=0;
}
if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
    B=0;
}
sort(a+1,a+n+1);
if(A==1||B==1){


         long long x=m;
    for(int j=n;j>=1;j--){
        if(x>=a[n]-a[j]){
        x=x-a[n]+a[j];
        cnt++;
        }
        else
            break;
    }

        cout<<cnt<<endl;
        return 0;


    }


if(A==0&&B==0){
for(int i=2;i<=n;i++){
    cnt=1;
    long long x=m;
    for(int j=i-1;j>=1;j--){
        if(x>=a[i]-a[j]){
        x=x-a[i]+a[j];
        cnt++;
        }
        else
            break;


    }
    max01=max(max01,cnt);
}
cout<<max01<<endl;
}
    return 0;
}
