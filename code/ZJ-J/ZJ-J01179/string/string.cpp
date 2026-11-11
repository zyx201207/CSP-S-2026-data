#include <bits/stdc++.h>
using namespace std;
long long n,i,j,ans,m;
struct op{
	long long l;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;i=1;j=n;
	for(int p=1;p<=n;++p){
		cin>>a[p].l>>a[p].c;
	}
	while(i<j){
		if(a[j].l==0) j--;
		while(a[i].l>0){
			if(a[i].l>a[j].l){
				if(a[i].c!=a[j].c) ans+=a[j].l;
				a[i].l-=a[j].l;a[j].l=0;
			}
			else {
				if(a[i].c!=a[j].c) ans+=a[i].l;
				a[j].l-=a[i].l;a[i].l=0;
			} 
			if(a[j].l==0) j--;
		}
		i++;
	}
	cout<<ans;
	return 0;
}