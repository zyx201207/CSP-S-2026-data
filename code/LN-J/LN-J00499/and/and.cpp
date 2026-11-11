#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x[200005],ans=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+n+1,cmp);
    for(int i=2;i<=m;i++){
        x[1]&=x[i];
    }
    cout<<x[1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
