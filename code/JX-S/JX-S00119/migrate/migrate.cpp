#include<bits/stdc++.h>
using namespace std;
int c,t;
int n[100005],d[100005];
int x[200005][200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
            cin>>n[i]>>d[i];
        for(int j=0;j<n[i];j++){
            cin>>x[i][j];
        }
    }
    int step=0;
    for(int i=0;i<t;i++){
        for(int j=i+1;j<n[i];j++){
            if(x[i][j]-d[i]<=x[i][0] && x[i][j]+d[i]>=x[i][n[i]]){
               step++;
            }
        }
        cout<<step;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
