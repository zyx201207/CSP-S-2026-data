#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct node{
	long long yuan;
	string he;
	long long yi;
}a[200005];
bool cmp(node x,node y){
	if(x.yi!=y.yi)return x.yi>=y.yi;
	return x.he<y.he;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].yuan;
		a[i].he=" ";
		long long x=a[i].yuan;
		while(x){
			a[i].he+=(char)(x%2+'0');
			if(x%2==1){
				a[i].yi++;
			}
			x/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].yuan;
	for(int i=2;i<=m;i++){
		if(a[i].yuan==0)continue;
		ans=(ans & a[i].yuan);
	}
	cout<<ans;
	return 0;
}
