#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],s,e;
	long long ans=0;
	char c[200005]={};
	scanf("%d",&n);
	s=1;e=n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		getchar;
	}
	while(s<e){
		if(a[s]>a[e]){
			if(c[s]!=c[e]){
				ans=ans+a[e];
			}
			a[s]=a[s]-a[e];
			e--;
		}
		else if(a[s]==a[e]){
			if(c[s]!=c[e]){
				ans=ans+a[s];
			}
			e--;
			s++;
		}
		else if(a[s]<a[e]){
			if(c[s]!=c[e]){
				ans=ans+a[s];
			}
			a[e]=a[e]-a[s];
			s++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
