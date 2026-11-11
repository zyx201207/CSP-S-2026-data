#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;
	bool xx=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			xx=1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	if(xx){
		x=-x;
	}
}
int n,l=1,r;
long long ans;
struct S{
	int x;
	char y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		read(a[i].x);
		char xc=getchar();
		while(xc<'a'||xc>'z'){
			xc=getchar();
		}
		a[i].y=xc;
	}
	while(l<r){
		if(a[l].x==a[r].x&&a[l].y==a[r].y){
			l++;
			r--;
		}else if(a[l].x!=a[r].x&&a[l].y==a[r].y){
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else{
				a[r].x-=a[l].x;
				l++;
			}
		}else if(a[l].x==a[r].x&&a[l].y!=a[r].y){
			ans+=a[l].x;
			l++;
			r--;
		}else if(a[l].x!=a[r].x&&a[l].y!=a[r].y){
			if(a[l].x>a[r].x){
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}else{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}