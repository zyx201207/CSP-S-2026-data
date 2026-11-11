#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int M=5e5+10; 
typedef long long ll;
int n,m,p,len;
int vis[N],a[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&p);
		bool flag=0;
		for(int j=1;j<i;j++){
			if(a[j]=0){
				break;
			}
			if(flag==1){
				a[j]=0;
			}
			if(a[j]==p){
				flag=1;
				a[j]=p;
				len=j;
			}
		}
		for(int j=1;j<=len;j++){
			vis[a[j]]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
