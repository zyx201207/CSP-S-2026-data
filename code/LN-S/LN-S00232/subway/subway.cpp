#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=0;i<p;i++){
        cout<<(c+n+m+d+p)/2+3;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
