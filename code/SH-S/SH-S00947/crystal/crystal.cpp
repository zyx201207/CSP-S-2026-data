#include<cstdio>
#include<iostream>
#include<algorithm>
long long s[500005],data[500005],ans=0,n,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&data[i]);
	}	//落差<=k可执行 
	std::sort(data+1,data+n+1);
	for(int i=1;i<=n;i++){	s[i]=s[i-1]+data[i];}
	for(int r=n,l=n;r>=1 && l>1;r--){
		//查找l使得[l,r]为合法区间，元素数（r-l+1）,实际区间和s[r]-s[l-1] 
		//合法区间和data[r]*(r-l+1)，落差为合法区间和-实际区间和
		while(l>1 && data[r]*(r-(l-1)+1)-(s[r]-s[l-1-1])<=k)	l--;
		if(ans<r-l+1){
			ans=r-l+1;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
} 
