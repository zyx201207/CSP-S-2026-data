#include <bits/stdc++.h>
using namespace std;
struct p{
	int r;
	char t;
};
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	//cout<<1<<endl;
	p a[200005];
	long long ans=0,n;
	//cout<<1<<endl;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].r>>a[i].t;
	}
	//cout<<1<<endl;
	for (int j=1,k=n;j<k;){
		if (a[j].t!=a[k].t){
			if (a[j].r==a[k].r){
				ans+=a[j].r;
				j++;
				k--; 
				//cout<<1<<endl;
			}
			if (a[j].r<a[k].r){
				a[k].r-=a[j].r;
				ans+=a[j].r;
				j++;
				//cout<<2<<endl;
			}
			if (a[j].r>a[k].r){
				a[j].r-=a[k].r;
				ans+=a[k].r;
				k--;
				//cout<<3<<endl;
			}
		}
		else {
			if (a[j].r==a[k].r){
				j++;
				k--; 
				//cout<<1<<endl;
			}
			if (a[j].r<a[k].r){
				a[k].r-=a[j].r;
				//cout<<1<<endl;
				j++;
			}
			if (a[j].r>a[k].r){
				a[j].r-=a[k].r;
				//cout<<1<<endl;
				k--;
			}
		}
	}
	cout<<ans;
	return 0;
}
