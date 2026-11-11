#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int xt[300005],dt[300005],a[500005];
stack<int>zm;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(xt,0,sizeof(xt));
		for(int j=i;j<=n;j++){
			if (xt[a[j]]==0){
				zm.push(j);
				xt[a[j]]=1;
			}
			else{
				while(a[zm.top()]!=a[j]){
					int ct=zm.top();
					zm.pop();
					xt[a[ct]]--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			dt[j]+=xt[j];
		}
	}
	
		for(int i=1;i<=m;i++){
		    printf("%d ",dt[i]);
	    }
	
	return 0;
}
