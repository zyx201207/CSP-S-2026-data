#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int f=1,s=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return f*s;
}
int n,tot,ans;
long long a[500005],k,m;
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		tot=1;
		k=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=k){
				tot++;
				k-=a[i]-a[j];
			}
			else{
				break; 
			}
		}
		ans=max(ans,tot);
	}
	printf("%d\n",ans);
}
