#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c, n, m, d, q,w[100001],k;
   cin >> c, n, m, d, q,a1[1001],a2[1001],t1[1001],t2[1001],r,x[1001],y[1001];
   for(int i = 1;i<=m;i++)
   {
	   cin >> w[i];
   }
   cin >> k;
   for(int i = 1; i<= k; i++)
   {
	   cin>>a1[i]>>a2[i]>>t1[i]>>t2[i];
   }
   for(int i;i<=n;i++;)
   {
	   cin >> x[i] >> y[i];
   }
    return 0;
}
