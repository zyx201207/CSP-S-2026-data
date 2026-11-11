#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans = 0;
bool cmp(int& t1,int& t2){
    return t1>t2;
}
void dfs(int p,int d,int num){
    if(num<=ans){
        return;
    }
    if(d == 0){
        ans = num;
        return;
    }
    if(p+d>n){
        return;
    }
    dfs(p+1,d-1,num&a[p]);
    dfs(p+1,d,num);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
    }
    //sort(a,a+n,cmp);
    dfs(0,m,INT_MAX);
    printf("%d",ans);
    return 0;
}
