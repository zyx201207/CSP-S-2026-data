#include<bits/stdc++.h>
using namespace std;
long long read(){
	char ch=getchar();
	long long dat=0,t=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
const long long N=2e6+10;
long long c,t;
long long n,d,a[N],ans,now;
bool yes(long long l,long long r){
	if(a[r]-a[l]>d) return 0;
	else return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	c=read();
	t=read();
	while(t--){
		n=read(),d=read();
		for(long long i=1;i<=n;i++) a[i]=read();
//		cout<<"aaaaaaaaaaaaaaaaa\n";
//		cout<<n<<" "<<d<<"\n";
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<"\n ans==\n";
		ans=0;
		for(long long i=1;i+3<=n;i++){
			if(!yes(i,i+3) && yes(i,i+2) && yes(i+1,i+3)){
				ans++;
				now=i+4;
				while(now<=n && (yes(now-1,now) && !yes(now-2,now))){
					ans++;
					now++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
