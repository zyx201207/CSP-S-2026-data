#include<iostream>
using namespace std;
struct node{
	int s;
	char c;
};
int n,l,r,ans=0;
node a[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].c,r+=a[i].s;
	l=1,r=n;
	while(l<r){
		if(a[l].s<a[r].s){
			if(a[l].c!=a[r].c)
				ans+=a[l].s;
			a[r].s-=a[l].s;
			l++;
		}else if(a[l].s>a[r].s){
			if(a[l].c!=a[r].c)
				ans+=a[r].s;
			a[l].s-=a[r].s;
			r--;
		}else{
			if(a[l].c!=a[r].c)
				ans+=a[l].s;
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
