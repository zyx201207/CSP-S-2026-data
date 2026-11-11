#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cd[500005]/*the cards on the desk*/;
int r[50005]/*the rests*/;
int np,last;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];        
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<=n;j++){
            np=a[j];
            for(int k=1;k<=last;k++){
                if(cd[k]==np){
                    int laste=last;
                    for(int f=k;f<=laste;f++){
                        cd[f]=0;
                        last--;
                    }
                    break;
                }
            }
            cd[last++]=np;
        }
        for(int j=1;j<=last;j++){
            r[cd[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<r[i]+1<<" ";
    }
    return 0;
}