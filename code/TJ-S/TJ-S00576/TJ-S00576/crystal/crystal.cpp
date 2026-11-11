#include<cstdio>
#include<algorithm>
int n;
long long m,a[500001],S[500001],cost,tmp,ans;
bool A=true,B=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		std::scanf("%lld",&a[i]);
		A&=(a[i]==i);
	}std::sort(a+1,a+n+1);
	for(int i=3;i<=n&&B;i++) B&=(a[i]-a[i-1]==a[i-1]-a[i-2]);
	if(A){
		cost=0;
		ans=1;
		for(long long i=1;cost<=m&&ans<n;i++){
			cost+=i;
			if(cost<=m) ans++;
		}std::printf("%lld\n",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}if(B){
		cost=0;
		ans=1;
		for(long long i=a[2]-a[1];cost<=m&&ans<n;i+=a[2]-a[1]){
			cost+=i;
			if(cost<=m) ans++;
		}std::printf("%lld\n",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}for(int i=1;i<=n;i++){
		cost=0;
		tmp=1;
		for(int j=i-1;j>=1;j--){
			cost+=a[i]-a[j];
			if(cost>m) break;
			tmp++;
		}ans=std::max(ans,tmp);
	}std::printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
