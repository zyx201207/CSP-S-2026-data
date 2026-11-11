#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nod{
	int s;
	char ch;
} a[200010];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].ch;
	}
	int x=1;
	int y=n;
	int ans=0;
	while(x<y){	
		if(a[x].ch==a[y].ch){
			if(a[x].s>a[y].s){
				a[x].s-=a[y].s;
				y--;
			} else if(a[x].s<a[y].s){
				a[y].s-=a[x].s;
				x++;
			} else {
				x++;
				y--;
			}
		} else {
			 if(a[x].s>a[y].s){
				ans+=a[y].s;
				a[x].s-=a[y].s;
				y--;
			} else  if(a[x].s<a[y].s){
				ans+=a[x].s;
				a[y].s-=a[x].s;
				x++;
			} else if(a[x].s==a[y].s){
				ans+=a[x].s;
				x++;
				y--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
