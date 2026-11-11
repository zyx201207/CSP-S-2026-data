#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3+10;
int c,t,n,d,stp1,stp2,a[MAXN],mini=MAXN,b[MAXN],e[MAXN],k,l,ALL=0;
bool can[MAXN][MAXN];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);    
    cin>>c>>t;
    for(int I=0;I<t;I++){
        // cout<<"R"<<endl;
        cin>>n>>d;
        ALL=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++){
                can[i][j]=0;
            }
        }
        k=0;
        l=1;
        // cout<<"E"<<endl;
        while(l<=n){
			if(a[l]-a[k]<=d){
                can[l][k]=can[k][l]=1;
                l++;
            }
            else{
                l--;
                for(int i=k;i<l;i++){
                    can[i][l]=can[l][i]=1;
                }
                k=l;
                l++;
            }
        }
        // cout<<"W"<<endl;
        for(int i=0;i<n-1;i++){
            for(int j=i+2;j<n;j++){
                if(can[i][j]){
                    continue;
                }
                k=i+1;
                stp1=stp2=0;
                while(!can[k][j]){
                    while(can[i][k]){
                        k++;
                    }
                    k--;
                    stp1++;
                }
                k=j-1;
                while(!can[i][k]){
                    while(can[k][j]){
                        k--;
                    }
                    k++;
                    stp2++;
                }
                if(stp1==stp2){ALL++;}
            }
        }
        cout<<ALL<<endl;
    }
    return 0;
}
