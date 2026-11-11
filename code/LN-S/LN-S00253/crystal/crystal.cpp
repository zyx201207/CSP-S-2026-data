#include<bits/stdc++.h>
using namespace std;
long long n,m,sum3=0,a[5000005],max1=0,m2;
int main(){

   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){

            m2=m;
            if(a[i]-a[j]<=m2){
                sum3++;
                m2=m2-(a[i]-a[j]);

            }else{
                break;
            }
        }
        sum3++;
        if(sum3>max1){
            max1=sum3;
        }

        m2=m;
        sum3=0;
    }
    cout<<max1;
    return 0;

}
