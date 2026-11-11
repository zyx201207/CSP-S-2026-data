#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cards[n];
    int exist[m+1]={0};
    for(int i=0;i<n;i++){
        cin>>cards[i];
    }
    for(int i=0;i<n;i++){
        int game[n-i]={0};
        for(int j=i;j<n;j++){
            game[j-i]=cards[j];
            for(int k=0;k<j-i;k++){
                if(game[k]==game[j-i]){
                    for(int u=k;u<j-i;u++){
                        game[u]=0;
                    }
                }
            }
        }
        for(int j=0;j<n-i;j++){
            exist[game[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<exist[i]<<' ';
    }
    return 0;
}
