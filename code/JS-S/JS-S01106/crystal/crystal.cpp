#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--){
        int cnt=1;
        int t=m;
        if(i<=ans){
            break;
        }
        int j=i-1;
        while(j){
            int cost=a[i]-a[j];
            if(t>=cost){
                t-=cost;
                cnt++;
                j--;
            }
            else{
                break;
            }
        }
        ans=max(ans,cnt);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
