#include<bits/stdc++.h>
using namespace std;
int n,o;
long long cnt;
int x[200005];
char z[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x[i]>>z[i];
		if(z[i]!=z[i-1]&&i>1) o=1;
	}
	if(o==0){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		if(z[l]!=z[r]){
			if(x[l]>=x[r]){
				x[l]-=x[r];
				cnt+=x[r];
				x[r]=0;
				r--;
			}else{
				x[r]-=x[l];
				cnt+=x[l];
				x[l]=0;
				l++;
			}
		}else{
			if(x[l]>=x[r]){
				x[l]-=x[r];
				x[r]=0;
				r--;
			}else{
				x[r]-=x[l];
				x[l]=0;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
