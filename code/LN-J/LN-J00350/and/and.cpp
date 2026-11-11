#include<bits/stdc++.h>
using namespace std;
int n,m,arr[10005],max01=-1000;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            max01=max(max01,arr[i]&arr[j]);
    }
    cout<<max01;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
