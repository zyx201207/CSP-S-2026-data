#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],st[500001],b[300001],lt[300001],as[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++)
        cin >>a[n-i+1];
    int t=0;
    for(int i=1;i<=n;i++){
        if(b[a[i]]==2)
            t=lt[a[i]],b[a[i]]=1;
        if(b[a[i]]==1)
            t=lt[a[i]],st[t]=a[i],b[a[i]]=2;
        if(b[a[i]]==0)
            st[++t]=a[i],b[a[i]]=2;
        lt[a[i]]=t;
        for(int j=1;j<=t;j++)
            as[st[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout <<as[i]<<' ';
	return 0;
}
