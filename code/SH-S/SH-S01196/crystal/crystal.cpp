#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int n,i,ans,j,daan;
ll m,a[maxn],maxs=-1e12-5,mins=1e12+5,b[maxn],s,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);	
	for(i=1;i<=n;i++){
		cin>>a[i];
		maxs=max(maxs,a[i]);
		mins=min(mins,a[i]);
	}
	if(n>5000&&maxs>100||n>5000&&mins<-100){
		sort(a+1,a+n+1);
		int g=a[2]-a[1];
		if(n%2){
			ans=1;
			for(i=1;i<(n+1)/2;i++){
				if(m>=2*g*i){
					m-=2*g*i;
					ans+=2;
				}
				else if(m>=g*i){
					ans++;
					break;
				}
				else break;
			}
		}
		else{
			long long mid=a[n/2];
			for(i=1;i<=n;i++){
				b[i]=max(a[i]-mid,mid-a[i]);
			}
			sort(b+1,b+n+1);
			for(i=1;i<=n;i++){
				if(m>=b[i]){
					m-=b[i];
					ans++;
				}
				else break;
			}
		}
		printf("%d",ans);
		return 0;
	}
	for(i=mins;i<=maxs;i++){
		s=i;
		ans=0;
		c=m;
		for(j=1;j<=n;j++){
			b[j]=max(a[j]-s,s-a[j]);
		}
		sort(b+1,b+n+1);
		for(j=1;j<=n;j++){
			if(c>=b[j]){
				c-=b[j];
				ans++;
			}
			else break;
		}
		daan=max(daan,ans);
	}
	printf("%d",daan);
	return 0;
}
