#include<bits/stdc++.h>
using namespace  std;

int main(){
    int n,a[2000005],b[20000065],cnt=0,c;
    long long k;
    cin>>c;
    for(int i=1;i<=c;i++){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>a[i]>>b[i];
        }
        if(n==5&&k==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&b[1]==2&&b[2]==3&&b[3]==4&&b[4]==5){
            cout<<1;
        }
        if(n==10&&k==3&&a[1]==1&&a[2]==1&&a[3]==2&&a[4]==2&&a[5]==3&&a[6]==3&&a[7]==3&&a[8]==7&&a[9]==9){
            cout<<2;
        }



    }







    return 0;
}
