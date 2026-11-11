#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long a_=a[l]<a[r]?2:1;
		if(a[l]==a[r]) a_=-1;
		if(c[l]==c[r]){
			if(a_==-1){
				l++;
				r--;
			}else if(a_==2){
				a[r]-=a[l];
				l++; 
			}else{
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a_==-1){
				ans+=a[l];
				l++;
				r--;
			}else if(a_==2){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
