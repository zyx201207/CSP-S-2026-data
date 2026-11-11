#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n,d;
	char a;
	scanf("%d %d",&c,&t);
	for(int o=0;o<t;o++){
		scanf("%d %d",&n,&d);
		int x[n],x1[n]={0};
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
			scanf("%c",&a);
		}
		int cnt=0;
		for(int i=0;i<n-3;i++){
			x1[i]=1;
			x1[i+1]=1;
			for(int j=i+2;j<n;j++){
				int p=j;
				while(1){
					if(x[j]-x[p]<=d)x1[j]+=x1[p];
					else break;
					p--;
				}
				if(x1[j]==2)cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}