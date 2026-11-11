#include<bits/stdc++.h>
using namespace std;
int m,n,d[10005],t[10005],e=1,t1,s;
bool b=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>d[i];
    }
    for(int i=0;i<m;i++){
        s=d[m-e];
        for(int j=m-e+1;j<m;j++){
            for(int k=0;k<m-e;k++){
                if(d[k]==d[j]){
                    t1++;
                    break;
                }
            }
        }
        t[s]=m-e+1-t1;
        e++;
        for(int i=1;i<=n;i++){
            if(t[i]==0) b=0;
        }
        if(b==1){
            for(int j=1;j<=n;j++){
                cout<<t[j]<<' ';
            }
            return 0;
        }
        else b=1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
