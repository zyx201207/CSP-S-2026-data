#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}	
	return f*ans;
}
const int N=5e5+10;
long long a[N],dif[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool b=0;
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				b=1;
			}
		}
	}
	if(b==0){
		int cnt=a[2]-a[1];
		for(int i=1;i<n;i++){
			if(m<(i*cnt)){
				cout<<i;
				return 0;
			}
			m-=(i*cnt);
		} 
		cout<<n;
		return 0;
	}
	else{
		int maxn=-1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i>=2){
				dif[i]=a[i]-a[i-1];
				
			}
		}
		int j=m;
		for(int i=2;i<=n;i++){
			m=j;
			for(int j=i;j<=n;j++){
				if(m<(j-i+1)*dif[j]){
					maxn=max(maxn,(j-i+1));
					break;
				}
				m-=(j-i+1)*dif[j];
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
