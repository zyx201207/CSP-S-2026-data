#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	int data;
	char s;
}a[200005];
long long len=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].data>>a[i].s;
		len+=a[i].data;
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l].data<a[r].data){
			if(a[l].s!=a[r].s) ans+=a[l].data;
			a[r].data-=a[l].data;
			l++;
		}
		else if(a[l].data>a[r].data){
			if(a[l].s!=a[r].s) ans+=a[r].data;
			a[l].data-=a[r].data;
			r--;
		}
		else if(a[l].data==a[r].data){
			if(a[l].s!=a[r].s) ans+=a[l].data;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

