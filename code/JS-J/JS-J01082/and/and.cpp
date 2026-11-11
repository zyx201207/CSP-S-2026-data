#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,arr[200005];
int ans=0;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int k,int num,int front_num){
    if(k>m){
        ans=max(ans,num);
        return;
    }
    if(num<=ans){
        return;
    }
    for(int i=front_num+1;i<=n;i++){
        if(arr[i]<ans){
            continue;
        }
        dfs(k+1,(num&arr[i]),i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+n+1,cmp);
    long long t=(1<<31)-1;
    dfs(1,t,0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;

}
