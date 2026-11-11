#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+3;
int n;
ll m;
ll a[N];
int ans;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int f1=1,f2=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			f1=0;
			break;
		}
	}
	if(f1){
		for(int i=1;i*(i+1)<=m&&i*2+1<=n;i++) ans=i;
		if(m-ans*(ans+1)>ans+1) ans=ans*2+2;
		else ans=ans*2+1;
		write(ans);
		return 0;
	}
	int c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			f2=0;
			break;
		}
	}
	if(f2){
		for(int i=1;((i-1)/c+1)*(i+1)<=m&&i*2+1<=n;i++) ans=i;
		cout<<c<<" "<<ans<<endl;
		if(m-((ans-1)/c+1)*(ans+1)>ans+c) ans=ans/c*2+2;
		else ans=ans/c*2+1;
		write(ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		ll rest=m;
		queue<int> cq;
		queue<int> bq;
		for(int j=i-1;j>=1;j--){
			cq.push(a[i]-a[j]);
		}
		for(int k=i+1;k<=n;k++){
			bq.push(a[k]-a[i]);
		}
		while(rest>0){
			if(cq.empty()&&bq.empty()) break;
			if(cq.empty()){
				rest-=bq.front();
				bq.pop();
				cnt++;
				continue;
			}
			if(bq.empty()){
				rest-=cq.front();
				cq.pop();
				cnt++;
				continue;
			}
			int qt=cq.front(),bt=bq.front();
			if(qt>bt){
				rest-=bt;
				bq.pop();
				cnt++;
			}else if(qt<=bt){
				rest-=qt;
				cq.pop();
				cnt++;
			}else break;
		}
		if(rest<0) cnt--;
		if(cnt>ans) ans=cnt;
	}
	write(ans);
	return 0;
}