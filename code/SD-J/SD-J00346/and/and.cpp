#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
//---SD-J00346---//
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=INT_MIN,tc7ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			tc7ans=a[1];
		}
		if(m==1){
			ma=max(ma,a[i]);
		}
		if(m==n){
			tc7ans=tc7ans&a[i];
		}
	}
	if(m==1){
		cout<<ma;
		return 0;
	}else if(m==n){
		cout<<tc7ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	return 0;
}
