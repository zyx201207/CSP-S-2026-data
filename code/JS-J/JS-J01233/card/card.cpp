#include <bits/stsc++.h>
using namepace std;
int n,m,a[500005];
int visit[500005],b[500005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        visit[a[i]]++;
    }
    bool flag;
    for (int i=2;i<=n;i++){
    	if (a[i]<=a[i-1])flag=false;
    }
    if (flag) {
    	for (int i=1;i<=n;i++){
    	    cout<<i;
    	}
    	return 0;
    }
    for (int i=n;i>=1;i--){
        if (visit[i]==1){
           continue;
        }
        if (visit[i]!=0){
            b[i]=-2;
            visit[a[i]]=0;
        }else b[i]=-1;
    }
    for (int i=n;i>=1;i--){
    	if (b[i]==-2){
    	    for (int j=i;j<=n;j++){
    	    	c[i]+=j;
    	    }
    	}
    }
    for (int i=1;i<=n;i++){
    	if (b[i]==-1){
    	    for (int j=i+1;j<=n;j++){
    	    	if (b[j]==-1){
    	    	    c[j]=max(c[j],j-i);
    	    	    i=j;
    	    	    break;
    	    	}
    	    	c[j]=max(c[j],j-i);
    	    }
    	}
    }
    for (int i=1;i<=n;i++){
    	cout<<c[i]<<" ";
    }
    return 0;
}
