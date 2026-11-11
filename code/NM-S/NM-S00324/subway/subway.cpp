#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,m,n,d,q,i1,i2,i3;
    cin>>c>>n>>m>>d>>q;
    vector<long long>w(m);
    vector<vector<long long>>z(m,vector<long long>(m,-1));
    for(long long i=0;i<m;i++){
        cin>>w[i];
    }
    for(long long i=0;i<n;i++){
        //cout<<'|';
        cin>>i1;
        vector<pair<long long,long long>>l(i1);
        for(long long j=0;j<i1;j++){
            cin>>i2>>i3;
            l[j]={i2-1,i3};
            for(long long l1=j-1;l1>=0;l1--){
                if(z[l[l1].first][i2-1]==-1||z[l[l1].first][i2-1]<l[l1].second+l[j].second){
                    z[l[l1].first][i2-1]=l[l1].second+l[j].second;
                }
                if(z[i2-1][l[l1].first]==-1||z[i2-1][l[l1].first]<l[l1].second+l[j].second){
                    z[i2-1][l[l1].first]=l[l1].second+l[j].second;
                }
            }
        }
    }
    for(long long i=0;i<m;i++){
        for(long long j=i;j<m;j++){
            if(i==j)continue;
            for(long long k=i;k<m;k++){
                if(i==k||j==k||z[i][k]==-1||z[k][j]==-1)continue;
                if(z[i][j]>z[i][k]+z[k][j]||z[i][j]==-1){
                    z[i][j]=z[i][k]+z[k][j];
                }
            }
        }
    }
    //for(vector<long long> i:z){for(long long j:i){cout<<j<<' ';}cout<<'\n';}
    while(q--){
        cin>>i1>>i2;
        if(i1>i2)swap(i1,i2);
        cout<<w[i1-1]+w[i2-1]+z[i1-1][i2-1]<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
