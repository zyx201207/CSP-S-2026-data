//SN-S00505 王梓桐 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=INT_MIN,sum,b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a;
	for(long long i=0;i<n;i++){
		cin>>b;
		a.push_back(b);
	}
	sort(a.begin(),a.end());
	sum=m;
	for(long long i=0;i<(int)a.size();i++){
		sum+=a[i];
		if(sum%(i+1)==0){
			ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
}
