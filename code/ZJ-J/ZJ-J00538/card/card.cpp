#include<bits/stdc++.h>
//#define int long long
using namespace std;
bool f=0;
long long n,m,a[500010],to[5010],last[3010],ans[300010],near[5010],ss=0,b[5010],s[0010],sss[500010],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]) f=1;
		if(i>1&&a[i]!=a[i-1]) ss++;
	}
	if(f==0){
//		cout<<"QWQWQWQW"<<endl;
		for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],(long long)i);
		for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
		return 0;
	}
	if(ss<=4999&&n>5000){
//		cout<<"WQDHQWDUHYDTYIAS"<<endl;
		sss[1]=1;
		for(int i=2;i<=n+1;i++){
			sss[i]=1;
			if(a[i]==a[i-1]) sss[i]=sss[i-1]+1;
			else b[++cnt]=a[i-1],s[cnt]=sss[i-1];
		}
		for(int i=cnt;i>=1;i--){
			if(last[b[i]]) to[i]=last[b[i]];
			last[b[i]]=i;
		}
		for(int pos=1;pos<=cnt;pos++){
			for(int i=pos;i<=cnt;i++){
				while(to[i]) i=to[i];
				ans[b[i]]+=s[i];
			}
		}
		for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(last[a[i]]) to[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int pos=1;pos<=n;pos++){
		for(int i=pos;i<=n;i++){
			while(to[i]) i=to[i];
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}