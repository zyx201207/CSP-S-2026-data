#include<bits/stdc++.h>
using namespace std;
const int maxx=5e5+5;
int n;
unsigned long long m;
unsigned long long a[maxx];
unsigned long long s[maxx];
unsigned long long s2[maxx];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%ull",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%ull",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i]-a[i-1];
		s2[i]=s2[i-1]+s[i];
	}
	int l=1;
	for(int r=1;r<=n;r++){
		while((r-l+1)*s[r]-s2[r]+s2[l-1]>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
