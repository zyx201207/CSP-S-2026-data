#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m,need=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		need+=(a[i]-a[i-1])*(i-1);
	}
	int l=1,r=n;
	while(l<=r){
		if(need<=m){
			cout<<r-l+1;
			return 0;
		}
		if(a[l+1]-a[l]>a[r]-a[r-1]){
			need-=(a[l+1]-a[l])*(r-l);
			l++;
			cout<<l<<" "<<r<<" "<<need<<"\n";
		}
		else if(a[l+1]-a[l]<a[r]-a[r-1]){
			need-=(a[r]-a[r-1])*(r-l);
			r--;
			cout<<l<<" "<<r<<" "<<need<<"\n";
		}
		else{
			int tmpl=l,tmpr=r;
			while(1){
				tmpl++,tmpr--;
				if(a[tmpl+1]-a[tmpl]!=a[tmpr]-a[tmpr-1])break;
				if(tmpl>=tmpr)break;
			}
			if(a[tmpl+1]-a[tmpl]>a[tmpr]-a[tmpr-1]){
				while(1){
					need-=(a[l+1]-a[l])*(r-l);
					if(need<=m){
						cout<<r-l;
						return 0;
					}
					l++;
					cout<<l<<" "<<r<<" "<<need<<"\n";
					if(l==tmpl)break;
				}
			}
			else{
				while(1){
					need-=(a[r]-a[r-1])*(r-l);
					if(need<=m){
						cout<<r-l;
						return 0;
					}
					r--;
				 	cout<<l<<" "<<r<<" "<<need<<"\n";
					if(r==tmpr)break;
				}
			}
		}
	}
	cout<<1;
	return 0;
}