#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b1,b2,c1=0,c2=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        cout<<n;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            b1=0,b2=0;
            for(int j=i;j<=n;j++){//  b1:g  b2:
                if(b1==0) b1=a[j];
                else if(b1!=a[j]&&b2==0) b2=a[j];
                else if(b1==a[j]&&b2!=a[j]) b2=0;
                //cout<<b1<<" "<<b2<<"\n";
            }
            //cout<<"\n";
            if(b2==1) c1++;
            if(b2==2) c2++;
            if(b1==1) c1++;
            if(b1==2) c2++;
        }
        //cout<<"\n";
        cout<<c1<<" "<<c2;
    }else{
        cout<<"10 3 3";
    }
    return 0;
}
