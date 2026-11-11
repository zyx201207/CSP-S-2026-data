#include<bits/stdc++.h>
using namespace std;
int bucket[300030];
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;

}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    pair<int,int> bl[300030];
    int c[500010];
    for(int i=0;i<n;i++){
        cin>>bl[i].first;
        bl[i].second=i;
    }
    for(int i=0;i<m;i++){
        int now[500040];int n_i=0;

        for(int j=i;j<n;j++){
            now[n_i++]=c[j];
            string state="check";
            for(int k=0;k<n_i-1;k++){
                if(now[n_i]==now[k]){
                    state="clear";
                }
                if(state=="clear"){
                    now[k]=-1;
                }
            }
        }
        for(int j=i;j<n;j++){
            if(now[j]!=-1){
                bucket[c[j]]++;
            }
        }
    }
    sort(bl,bl+m,cmp);
    for(int i=0;i<=m;i++){
        cout<<bl[i].second+1<<' ';
    }
    return 0;
}
