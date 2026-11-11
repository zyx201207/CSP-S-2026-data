#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long cnt;
struct c{
	int l;
	char x;
}a[200005];
int  minn=1,maxx=n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].x;
	}
	while(1){
		if(maxx<minn){
			break;
		}
		if(a[minn].x!=a[maxx].x){
			cnt=cnt+min(a[maxx].l,a[minn].l);
		}
		if(a[maxx].l>a[minn].l){
			a[maxx].l-=a[minn].l;
			minn++;
		}
		else if(a[maxx].l<a[minn].l){
			a[minn].l-=a[maxx].l;
			maxx--;
		}
		else{
			maxx--;
			minn++;
		}
	}
	cout<<cnt;
	return 0;
}
