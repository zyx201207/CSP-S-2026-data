#include<bits/stdc++.h>
using namespace std;
long long n,v[200005];
char c[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>c[i];
	}
	long long l=1,r=n,ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(v[l]<v[r]){
				v[r]-=v[l];
				l++;
			}
			else if(v[l]>v[r]){
				v[l]-=v[r];
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(v[l]<v[r]){
				v[r]-=v[l];
				ans+=v[l];
				l++;
			}
			else if(v[l]>v[r]){
				v[l]-=v[r];
				ans+=v[r];
				r--;
			}
			else{
				ans+=v[r];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}