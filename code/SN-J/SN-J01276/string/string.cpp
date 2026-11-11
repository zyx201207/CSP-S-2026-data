#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int x=1,y=n;
	while(x<y){
		//不一样就修改短的 
		if(c[x]!=c[y]) ans+=min(a[x],a[y]);
		//截去短的 
		if(a[x]<a[y]){
			a[y]-=a[x];
			a[x]=0;
			x++;
		}
		else if(a[x]>a[y]){
			a[x]-=a[y];
			a[y]=0;
			y--;
		}
		else{
			a[y]=0;
			a[x]=0;
			y--;
			x++;
		}
	}
	//x=y时则已经回文 
	cout<<ans;
	return 0;
}
//浪子为君歌一曲，劝君切莫把泪流。
//人间若有不平事，纵马挥刀斩人头。 
