#include<bits/stdc++.h>
int a[200007];
char s[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)std::cin >> a[i] >> s[i];
	unsigned long long k=0,l=0,r=n-1,ans=0,ll=0,rl=0;
	while(l<r){
		if(s[l]!=s[r])ans+=std::min(a[l]-ll,a[r]-rl);
		if(a[l]-ll<a[r]-rl){
			rl+=a[l]-ll;
			ll=0;
			l++;
		}
		else if(a[l]-ll>a[r]-rl){
			ll+=a[r]-rl;
			rl=0;
			r--;
		}
		else if(a[l]-ll==a[r]-rl){
			l++;
			r--;
			ll=0;
			rl=0;
		}
	}
	std::cout << ans << '\n';
	return 0;
}
