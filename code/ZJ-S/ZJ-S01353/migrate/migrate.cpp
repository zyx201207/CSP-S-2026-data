#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void write(LL x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
LL T,n,m,a[2000005],ans,f[2000005][2],L[2000005],R[2000005],tmp1;
int find_1(int x,int y,int p){
	int ans=-1;
	while(x<=y){
		int mid=(x+y)/2;
		if(R[p]-L[mid]+1>=2){
			x=mid+1;
		}else{
			ans=mid;
			y=mid-1;
		}
	}
	return ans;
}
int find_3(int x,int y,int p){
	int ans=-1;
	while(x<=y){
		int mid=(x+y)/2;
		if(R[p]-L[mid]+1<=2){
			y=mid-1;
		}else{
			ans=mid;
			x=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	T=read();T=read();
	while(T--){
		n=read();m=read();ans=0;tmp1=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			f[i][0]=1;f[i][1]=0;
		}
		for(int i=1;i<=n;i++){
			while(a[i]-a[tmp1]>m){
				R[tmp1]=i-1;
				tmp1++;
			}
		}
		while(tmp1<=n){
			R[tmp1]=n;
			tmp1++;
		}
		tmp1--;
		for(int i=n;i>=1;i--){
			while(a[tmp1]-a[i]>m){
				L[tmp1]=i+1;
				tmp1--;
			}
		}
		while(tmp1>=1){
			L[tmp1]=1;
			tmp1--;
		}
		for(int i=1;i<=n;i++){
			ans+=(R[i]-i)*f[i][1];
			if(R[i]==i){
				ans+=f[i][1];
				continue; 
			}
			int x=R[R[i]];
			if(x==R[i]){
				f[R[i]][1]+=f[i][1];
				continue;
			}
			if(R[i]-L[x]+1>=3){
				ans+=f[i][1];
				continue;
			}
			int y=find_1(R[i]+1,x,i),z=find_3(R[i]+1,x,i);
			if(y==-1){
				if(z==-1)z=R[i];
				ans+=(x-z-1)*f[i][0];
				f[x][1]+=f[x][0];
			}else{
				f[R[i]][0]+=f[i][0];
				f[x][1]+=f[i][1]; 
				if(z==-1)z=R[i];
				ans+=(x-y)*f[i][1]+f[i][0]*(y-z-1);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
