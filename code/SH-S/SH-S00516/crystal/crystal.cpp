#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a;
	for(int i=0;i!=n;i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	long long num=0;
	int ans,l,r;
	ans=0;
	l=0;
	r=0;
	while(r<n){
		if(r!=0)num+=((r-l)*(a[r]-a[r-1]));
		while(num>m){
			num-=(a[r]-a[l]);
			l++;
		}
		
		//cout<<r<<' '<<l<<' '<<num<<endl;
		
		if((r-l+1)>ans){
			ans=r-l+1;
		}
		r++;
	}
	cout<<ans;
	return 0;
} 
