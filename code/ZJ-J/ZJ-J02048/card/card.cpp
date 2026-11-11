#include<iostream>
using namespace std;
int n,m,a[500005]={},b[300005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			int s=j,e=n;
			while(s<=e){
				if(a[e]==a[s]){
					b[a[s]]++;
					s=e+1;
					e=n;
					break;
				}
				e--;
			}
			j=s;
		}
	}
	for(int i=1;i<=300005;i++){
		if(b[i]!=0){
			printf("%d ",b[i]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
