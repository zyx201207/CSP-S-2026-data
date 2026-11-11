#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n>5000){
		bool ok=true;
		int num=a[2]-a[1];
		for(int i=1;i<=n;++i){
			if(num!=a[i+1]-a[i]){
				ok=false;
				break;
			}
		}
		if(ok){
			int xx=m%num;
			int y=(m-xx)%num;
			int pp=0;
			while(pp++){
				if(y>=pp){
					y-=pp;
				}else break;
			}
			cout<<pp+1<<endl;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;--i){
		int x=m,y=i,ansi=0;
		while(x>=0&&y>=1){
			if(a[i]-a[y]<=x){
				ansi++;
				x-=(a[i]-a[y]);
				y--;
			}else{
				break;
			}
		}
		ans=max(ansi,ans);
	}
	cout<<ans<<endl;
	return 0;
} 
