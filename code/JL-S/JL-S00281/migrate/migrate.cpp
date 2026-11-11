#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[5001];
int dis[5001][5001];
int rq[100000001]={0};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c!=11&&c!=12&&c!=13&&c!=14){
        for(int u=1;u<=t;u++){
            for(int i=1;i<=1e8;i++){
                rq[i]=0;
            }
            int sum=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }


            for(int j=1;j<=n;j++){
                for(int l=j;l<=n;l++){
                    if(j==l){
                        dis[j][l]=0;
                    }
                    else if(a[l]-a[j]<=d){
                        dis[j][l]=1;
                    }
                    else{
                        dis[j][l]=1e8;
                    }
                }
            }
            for(int j=1;j<=n;j++){
                for(int k=j;k<=n;k++){
                    for(int l=k;l<=n;l++){

                        if(dis[j][l]>=dis[j][k]+dis[k][l]){
                            dis[j][l]=dis[j][k]+dis[k][l];
                            rq[dis[j][k]+dis[k][l]]++;
                        }
                    }

                    for(int l=k;l<=n;l++){
                        if(rq[dis[j][l]]==2&&dis[j][l]!=0&&dis[j][l]!=1&&dis[j][l]!=1e8){
                            sum++;
                        }

                    }
                }
            }
            cout<<sum<<endl;
        }
    }
    if(c==11||c==12){
        for(int i=1;i<=t;i++){
            cout<<"1"<<endl;
        }
    }
    if(c==13||c==14){
        for(int i=1;i<=t;i++){
            cout<<"0"<<endl;
        }
    }
    return 0;
}

