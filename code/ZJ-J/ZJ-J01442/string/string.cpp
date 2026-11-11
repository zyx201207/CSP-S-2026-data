#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll x[200005];
char c[200005];
ll cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(x[l]>x[r]){
				x[l]-=x[r];
				r--;
			}
			else if(x[l]<x[r]){
				x[r]-=x[l];
				l++;
			}
			else{
				r--;
				l++;
			}
		}
		else{
			if(x[l]>x[r]){
				x[l]-=x[r];
				cnt+=x[r];
				r--;
			}
			else if(x[l]<x[r]){
				x[r]-=x[l];
				cnt+=x[l];
				l++;
			}
			else{
				cnt+=x[l];
				r--;
				l++;
			}
		}
	}
	cout<<cnt;
	
	
	return 0;
}
			