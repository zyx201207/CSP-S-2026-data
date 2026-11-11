#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+109;
#define int long long
const int p1=1e9+7,p2=998244353;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+(int)(c-'0');
		c=getchar();
	}
	return k*f;
}
int l[maxn],r[maxn],s1[maxn],s2[maxn];
int x[maxn],n,d,ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		ans=0;
		for(int i=1;i<=n;i++){
			x[i]=s1[i]=s2[i]=l[i]=r[i]=0;
		}
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(n>5001){
			int k=x[2]-x[1];
			if(k<d&&d<=2*k){
				cout<<n-3<<endl;
			}
			cout<<0<<endl;
			continue;
		}
		for(int i=1,j=1;i<=n;i++){
			while(x[i]-x[j]>d){
				j++;
			}
			l[i]=j;
		}
		for(int i=n,j=n;i>0;i--){
			while(x[j]-x[i]>d){
				j--;
			}
			r[i]=j;
		}
		for(int i=1;i<=n;i++){
//			cout<<i<<":"<<endl;
			for(int j=i;j<=r[i];j++){
				s1[j]=s2[j]=1;
				s1[j]+=s1[j-1];
				s2[j]+=s2[j-1];
			}
			for(int j=r[i]+1;j<=n;j++){
				int x=l[j];
				s1[j]=s1[j-1]-s1[x-1];
				s1[j]=(s1[j]%p1+p1)%p1;
				s2[j]=((s2[j-1]-s2[x-1])%p2+p2%p2);
				if(s1[j]==2&&s2[j]==2){
					ans++;
				}
//				cout<<x<<" "<<s1[j]<<" "<<s2[j]<<endl;
				s1[j]=(s1[j]+s1[j-1])%p1;
				s2[j]=(s2[j]+s2[j-1])%p2;
			}
		}
		cout<<ans<<endl;
		
	} 
	fclose(stdin);
	fclose(stdout);	
}
