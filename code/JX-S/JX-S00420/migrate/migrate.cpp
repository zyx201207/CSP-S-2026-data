#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n[t],d[t];
    int x[t][10086];
    for (int i=0;i<t;i++){
        cin>>n[i]>>d[i];
        for (int j=0;j<n[i];j++){
            cin>>x[i][j];
        }
    }
    for (int i=0;i<t;i++){
        int y[n[i]-1]={};
        for (int j=0;j<n[i];j++){
            y[j]=x[i][j+1]-x[i][j];
        }
        int ax=0;
        for (int z=0;z<n[i]-1;z++){
            int D=d[i];
            int l[3]={};
            int s=z;
            for (int g=0;g<3;g++){
                D-=y[z+g];
                if (D==0){
                    l[g]=1;
                    D=d[i];
                }else if(D<0){
                    l[g]=1;
                    break;
                }else if(g==3){
                    l[g]=1;
                }
            }
            if (l[0]==0 && l[1]==1 && l[2]==1){
                ax+=1;
            }
        }
        cout<<ax<<endl;
    }
    return 0;
}
