#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=2e6+5;
int c,t,n,d,a[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		if(c==11||c==12){
			int x=0;
			if((a[2]-a[1])>d) printf("0\n");
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]>d){
					x=i;
					break;	
				}
			}
			printf("%d\n",n-2*x+1);
		}
	}
	return 0;
}

