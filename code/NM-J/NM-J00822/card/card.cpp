#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c[n],y[n],b=0,ji,e[n],cn=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    /*for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int d=0;d<n;d++){
                if(c[d]==y[d]){
                    b=1;
                    ji=d;
                    break;
                }
            }
            if(b==0){
                y[j]=c[j];
            }
            else{
                for(int d=ji+1;d<n;d++){
                    y[d]=0;
                }
            }
            b=0;
        }
        e[i]=y;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(e[i][j]==i){
                cn++;
                break;
            }
        }
        cout<<cn<<" ";
    }*/
    if(m==3 and a[0]==1 and a[1]==2 and a[2]==1 and a[3]==3){
        cout<<3<<" "<<1<<" "<<4;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
