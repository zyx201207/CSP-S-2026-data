#include<bits/stdc++.h>
using namespace std;
int n,m,rp[300013],fnn[300013];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>rp[i];
    }
    for(int i=1;i<=n;i++){
        queue <int> ys;
        int llz[300013];
        for(int j=i;j<=n;j++){
            ys.push(rp[j]);
        }
        int xxx=0,yss=ys.size();
        for(int j=1;j<=yss;j++){
            llz[j]=ys.front();
            xxx++;
            ys.pop();
            for(int l=1;l<xxx;l++){
                if(llz[l]==llz[j]){
                    int xx=xxx;
                    for(int k=l+1;k<=xx;k++){
                        llz[k]=0;
                        xxx--;
                    }
                    break;
                }
            }

            for(int s=1;s<=xxx;s++){
                cout<<llz[s]<<' ';
            }
            cout<<endl;
        }
        for(int j=1;j<=xxx;j++){
            cout<<' '<<llz[j]<<' ';
        }
        cout<<endl;
        for(int j=1;j<=yss;j++){
            fnn[llz[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<fnn[i]<<' ';
    }
    return 0;
}
