#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool v[300005];
int cnt[300005];
set<int>se;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++){
    scanf("%d",a+i);
   }
   for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(se.count(a[j])){
                se.clear();
                se.insert(a[j]);
            }
            else se.insert(a[j]);
        }
        for(int x:se){
            cnt[x]++;
        }
        se.clear();
   }
   for(int i=1;i<=m;i++){
    cout<<cnt[i]<<' ';
   }
return 0;
}


