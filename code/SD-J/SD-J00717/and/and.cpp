#include<cstdio>
using namespace std;
int a[2000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int s=0x40000000;
	while(s){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]&s){
				ans++;
			}
		}
		if(ans>=m){
			int toto=0;
			for(int i=0;i<n;i++){
				if(a[i]&s){
					a[toto]=a[i];
					toto++;
				}
			}
			n=toto;//toto=ans
		}
		s>>=1;
	}
	int ans=-1;
	for(int i=0;i<n;i++){
		ans&=a[i];
	}
	printf("%d",ans);
	return 0;
}
/*
1001101
1001010
*/
