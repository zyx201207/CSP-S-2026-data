#include<bits/stdc++.h>
using namespace std;
long long n,lens,ans;
struct node{
	long long a,sh;
	char c;
};
node g[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i].a>>g[i].c;
		g[i].sh=g[i].a;
		lens+=g[i].a;
	}
	long long y=lens/2,i=1,j=n;
	while(y!=0){
		long long ay=min(g[i].a,y);
		while(ay!=0){
			long long minn=min(ay,g[j].sh);
			if(g[i].c!=g[j].c){
				ans+=minn;
			}
			ay-=minn;
			y-=minn;
			g[j].sh-=minn;
			if(g[j].sh==0){
				j--;
			}
		}
		i++;
	}
	cout<<ans;
	return 0;
}
