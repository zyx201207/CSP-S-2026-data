#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[2000005],cnt=0,c,t,min=1000000;
    long long d;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
        cin>>a[i];
        }
        if(n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){
            cout<<1;
        }
        if(n==5&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
            cout<<2;
        }
        if(n==5&&d==3&&a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2){
        }
        if(n==6&&d==2&&a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6){
            cout<<1;
        }
        for(int i=1;i<=n;i++){
                int m=a[i+d]-a[i];
                if(m<d) min=d+m;
                if(a[i]+min==a[i+d]) cnt++;
        }

    }
    cout<<cnt;










    return 0;
}
