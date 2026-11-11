#include<bits/stdc++.h>
using namespace std;
inline long long rd(){
	long long x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()){
		if(ch=='-')f=-1;
	}
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f*x;
}
long long c,t,a[5010],n,d,ans,f[5010][5010],s[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd();
	t=rd();
	for(int qq=1;qq<=t;qq++){
		ans=0;
		n=rd();
		d=rd();
		for(int i=1;i<=n;i++){
			a[i]=rd();
		}
		for(int i=1,l=1;i<=n;i++){
			if(l<=i&&l<n)l=i;
			while(l<n&&a[l+1]-a[i]<=d){
				l++;
			}
			a[i]=l-i;
			for(int j=1;j<=i;j++){
				f[i][j]=1e9;
				s[i][j]=0;
			}
			for(int j=i+1;j<=l;j++){
				f[i][j]=1;
				s[i][j]=1;
			}
			for(int j=l+1;j<=n;j++){
				f[i][j]=1e9;
				s[i][j]=0;
			}
		}
		for(long long k=1;k<=n;k++){
			for(long long i=1;i<k;i++){
				for(long long j=max(a[i]+i+1,k+1);j<=n;j++){
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[i][k]+f[k][j];
						s[i][j]=s[i][k]*s[k][j];
						if(s[i][j]>2)s[i][j]=3;
					}
					else if(f[i][j]==f[i][k]+f[k][j]){
						s[i][j]+=s[i][k]*s[k][j];
						if(s[i][j]>2)s[i][j]=3;
					}
				}
			}
		}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(s[i][j]==2)ans++;
				}
			}
			printf("%lld\n",ans);
	}
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
inline long long rd(){
	long long x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()){
		if(ch=='-')f=-1;
	}
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f*x;
}
long long c,t,a[2000010],n,d,ans,sm[2000010],as[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd();
	t=rd();
	for(int qq=1;qq<=t;qq++){
		ans=0;
		n=rd();
		d=rd();
		for(int i=1;i<=n;i++){
			a[i]=rd();
		}
		for(int i=1,l=1;i<=n;i++){
			if(l<=i&&l<n)l=i;
			while(l<n&&a[l+1]-a[i]<=d){
				l++;
			}
			a[i]=l-i;
		}
		sm[n+1]=0;
		as[n+1]=as[n+2]=as[n+3]=0;
		for(int i=n,i>=1;i--){
			if(a[i]==0)sm[i]=sm[i+1],as[i]=0;
			if(a[i]==1)as[i]=as[i+1],sm[i]=sm[i+1]+as[i];
			if(a[i]==2)as[i]=a[a[i]+i-1]+a[i]+i-1-a[i]-i+sm[a[ a[i]+i-1]+a[i]+i]-sm[a[ a[i]+i]+a[i]+i+1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
*/