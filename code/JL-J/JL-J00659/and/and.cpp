#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,int y;
}a[100005];
bool(node x,node y){
    if(x>y)return x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1+n,a+1);
    int s=1;
    for(int i=1;i<=m;i++){
        s and a[i];
    }
    return 0;
}
