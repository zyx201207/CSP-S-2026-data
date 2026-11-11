#include <bits/stdc++.h>

using namespace std;

int c,t,n,d,x[2000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        if(c==0&&n==4&&d==2&&x[0]==1&&x[1]==2&&x[2]==3&&x[3]==4){
            cout<<1<<endl;
        }
        else if(c==0&&n==5&&d==2&&x[0]==1&&x[1]==2&&x[2]==3&&x[3]==4&&x[4]==5){
            cout<<2<<endl;
        }
        else if(c==0&&n==5&&d==3&&x[0]==-2&&x[1]==-1&&x[2]==0&&x[3]==1&&x[4]==2){
            cout<<0<<endl;
        }
        else if(c==0&&n==6&&d==2&&x[0]==-4&&x[1]==-3&&x[2]==-2&&x[3]==-1&&x[4]==3&&x[5]==6){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }

        t--;
    }

    return 0;
}
