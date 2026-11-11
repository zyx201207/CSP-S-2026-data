#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    vector<long> p;
    cin>>n>>m;
    int appear[m+1],card[n];
    for(int j=1;j<=m;j++){
        appear[j]=0;
    }
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    for(int i=0;i<n;i++){
        p.clear();
        for(int j=i;j<n;j++){
            for(int z=0;z<p.size();z++){
                if(p[z]==card[j]){
                    p.clear();
                }
            }
            p.push_back(card[j]);
        }
        for(int j=1;j<=m;j++){
            for(int z=0;z<p.size();z++){
                if(p[z]==j){
                    appear[j]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<appear[i]<<' ';
    }
    return 0;

}
