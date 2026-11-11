#include<iostream>
#include<cmath>
using namespace std;
const int N=2e5+100;
int a[N];
int x[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t;
	int s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t=a[i];
		s=1;
		while(t){
		    x[s]+=(t%2);
		    s++;
		    t/=2;
		}
	}
	int ans=(1LL<<32)-1;
	int n1=n;
	for(int i=31;i>=1;i--){
		if(x[i]<m)continue;
		if(n1<=m)break;
		if(x[i]>=m){
			for(int j=1;j<=n1;j++){
				if(n1<=m)break;
				if(!((1<<(i-1))&a[j])){
					for(int l=1;l<=31;l++){
						x[l]-=(((1<<(l-1))&a[j])>>(l-1));
					}
					swap(a[j],a[n1]);
					n1--;
					j--;
				}
			}
		}
		if(n1<=m)break;
	}
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}