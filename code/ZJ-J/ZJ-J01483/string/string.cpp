#include<bits/stdc++.h>
#define LL long long int
using namespace std;
struct node{
	LL l,r;
	char x;
}a[200009];
int n;
int find(int x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid].l<=x&&a[mid].r>=x){
			return mid;
		} else if(a[mid].l>x) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	LL len=0;
	for(int i=1,p=1;i<=n;i++){
		int x;
		cin>>x>>a[i].x;
		a[i].l=p;
		a[i].r=p+x-1;
		p+=x;
		len=p;
	}
	len--;
	LL ans=0;
	for(int i=1;i<=n;i++){
		for(LL j=a[i].l;j<=a[i].r;j++){
			if(a[i].x!=a[find(len-j+1)].x){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}