#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m,a[500005]={},cnt[300005]={},z=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[z]=x;
        z++;
        cnt[x]++;
        int zt=0;
        for(int j=1;j<=z;j++){
            if(a[j]==x)zt=1;
            if(zt)a[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
	return 0;
}
