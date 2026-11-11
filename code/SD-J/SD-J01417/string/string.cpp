#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[300040];
char c[300040];
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	
	int x=1,y=n;
	int ans=0;
	while(x<y){
		if(a[x]<=a[y])
		{
			if(c[x]!=c[y])
			ans+=a[x];
			a[y]-=a[x];
			x++;
			if(a[y]==0)y--;
			
		}else {
			if(c[x]!=c[y])
			ans+=a[y];
			a[x]-=a[y];
			y--;
			
		}
//		cout<<x<<' '<<y<<' '<<a[x]<<' '<<a[y]<<endl;
	}
	cout<<ans<<endl;
	fclose(stdout);
	fclose(stdin); 

	return 0;
} 
