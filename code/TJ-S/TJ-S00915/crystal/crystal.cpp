#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,x=0;long long m;
	cin>>n>>m;
	long a[500005],a0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int i0=i;
		while(i0!=0 & a[i0]<a[i0-1]){
			a0 = a[i0-1];
			a[i0-1] = a[i0];
			a[i0] = a0;
			i0--; 
		}
	}
	for(int i=0;i<n;i++){
		int s=0;
		int mj=m;
		for(int j=n;j>=0;j--){
			if(a[i]-a[j]<0)continue;
			mj -= a[i]-a[j];
			if(mj<0)break;
			s++;
		}
		if(s>x)x = s;
	}
	cout<<x;
	return 0;
}
