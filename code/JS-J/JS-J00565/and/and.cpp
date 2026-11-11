#include <bits/stdc++.h>
 
using namespace std;

int n,m,ans=-1;
int a[200010];

int and(int y){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)
            ans=max(ans,a[i]^a[j]);
    }
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    cin>>n>>m;
    int max=-1;
    int x=and(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        max=max(max,a[i]);
    }
    if(m==1) cout<<max; 
    if(m==2) cout<<x;

	fclose(stdin);
    fclose(stdout);
	return 0;
   
}
