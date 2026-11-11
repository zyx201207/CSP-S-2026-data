#include<bits/stdc++.h>
using namespace std;
long long n,ans,x=1,y;
string s;
struct S{
	long long a;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	y=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	while(x<y){
		if(a[x].a<a[y].a){
			if(a[x].c!=a[y].c){
				ans+=a[x].a;
			}
			a[y].a-=a[x].a;
			x++;
		}else if(a[x].a>a[y].a){
			if(a[x].c!=a[y].c){
				ans+=a[y].a;
			}
			a[x].a-=a[y].a;
			y--;
		}else{
			if(a[x].c!=a[y].c){
				ans+=a[x].a;
			}
			x++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}
