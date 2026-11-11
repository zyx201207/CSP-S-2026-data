#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long num[200008];
char str[200008];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>str[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(str[l]==str[r]){
			if(num[l]>num[r]){
				num[l]-=num[r];
				r--;
			}
			else if(num[l]<num[r]){
				num[r]-=num[l];
				l++;
			}
			else {
				num[l]=0;
				num[r]=0;
				l++;r--;
			}
		}
		else {
			if(num[l]>num[r]){ans+=num[r];
				num[l]-=num[r];
				r--;
				
			}
			else if(num[l]<num[r]){
				ans+=num[l];
				num[r]-=num[l];
				l++;
			}
			else {
				ans+=num[r];
				num[l]=0;
				num[r]=0;
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
