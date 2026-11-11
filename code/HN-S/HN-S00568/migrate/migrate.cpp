#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
long long n,d,a[2000005],c,t,b[2000005],f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		d=read();
		long long ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int k=1;k<=n;k++){
			memset(b,0,sizeof b);
			memset(f,0,sizeof f);
			b[a[k]]=1;
			//ans=0;
			for(int i=k;i<=n;i++){
				int j=i;
				while(j>=k){
					if(a[i]-a[j]<=d){
						if(b[a[j]]){
							f[i]++;
							b[a[i]]=1;
						}
					}else{
						break;
					}
					j--;
				}
			}
			for(int i=1;i<=n;i++){
				if(f[i]==2)ans++;
			}
		}
		cout<<ans/3<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
