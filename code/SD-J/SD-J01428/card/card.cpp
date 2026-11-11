#include<iostream>
#include<cstdio>
#include<cstring>
const int N=5e5+10;
const int M=3e5+10;
using namespace std;
int n,m;
int top;
long long t[N];
int a[N];
int x[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		memset(x,0,sizeof(x));
		top=0;
		for (int j=i;j<=n;j++){
			int bj=0;
			for (int k=1;k<=top;k++){
				if (x[k]==a[j]){
					top=k;
					bj=1;
					break;
				}
			}
			if (!bj){
				x[++top]=a[j];
			}
		}
		for (int j=1;j<=top;j++){
			t[x[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		printf("%lld ",t[i]);
	}
	return 0;
}
