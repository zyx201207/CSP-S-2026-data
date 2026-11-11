#include<bits/stdc++.h>
using namespace std;
int n,m,sum,res;
int as[200005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
      freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>as[i];
    }
    sort(as,as+n,cmp);
    for(int i=0;i<m-1;i++){
        as[i+1]=(as[i]&as[1+i]);
            }
    cout<<as[m-1];
    return 0;
}
