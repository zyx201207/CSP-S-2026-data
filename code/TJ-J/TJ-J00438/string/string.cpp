#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	ll sum=0;
	cin>>n;
	vector<pair<int,char>>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int l=0,r=n-1;
	while(l<=r){
		if(l+1==r&&a[l].second==a[r].second){
		sum+=0;	
		}else{
		if(a[l].second==a[r].second){
			sum+=abs(a[l].first-a[r].first);
		}else{
			sum+=abs(a[l].first-a[r].first)+min(a[l].first,a[r].first);
		}	
		}
		l++;
		r--;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
