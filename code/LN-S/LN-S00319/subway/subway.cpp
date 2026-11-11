#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    int a[m],b[n][100000];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=0;j<2*x;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<p;i++){
        cout<<2*b[i][2];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
