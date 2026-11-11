#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,cnt;
int a[N],b[N],t[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		cnt=0;
		for(int i=k;i<=n;i++){
			for(int j=1;j<=cnt;j++){
				if(b[j]==a[i]){
					cnt=j-1;
				}
			}
			b[++cnt]=a[i];
		}
		for(int i=1;i<=cnt;i++){
			t[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",t[i]);
	}
	return 0;
}
