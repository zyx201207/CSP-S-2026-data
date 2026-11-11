#include<bits/stdc++.h>
using namespace std;
struct card{
	bool seek;
	int i;
}f[300050];
int n,m,t,a[500050],s[300050],d[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		t=0;
		for(int i=k;i<=n;i++){
			if(f[a[i]].seek){
				int t1=t;
				t=f[a[i]].i;
				for(int j=f[a[i]].i+1;j<=t1;j++){
					f[s[j]].seek=0;
				}
			}
			else{
				t++;
				s[t]=a[i];
				f[a[i]].seek=1;
				f[a[i]].i=t;
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i].seek) d[i]++;
			f[i].seek=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",d[i]);
	}
	return 0;
}
