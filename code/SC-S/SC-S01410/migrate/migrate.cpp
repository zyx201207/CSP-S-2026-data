#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    //cout<<t;
    for(int i=0;i<t;i++){
        int n,d;
        cin>>n>>d;
        //cout<<n<<" "<<d<<endl;
        int num[n+1];
        for(int j=0;j<n;j++){
            cin>>num[j];
            //cout<<num[j]<<" "<<endl;
        }
        int ways;
        for(int q=0;q<n;q++){
            for(int laps=n-q;laps<n;laps++){
                if((num[laps]-q)%d!=0 && laps-q>=3){
                    ways+1;
                }
            }
        }
        cout<<ways<<" "<<endl;
    }
    return 1;
}
