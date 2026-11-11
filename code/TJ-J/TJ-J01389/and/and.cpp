#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	if(m==n){
		long long ans=a[0];
		for(int i=1;i<n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=-1;
		for(int i=1;i<n;i++){
			max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	long long ans=-1;
	do{
		long long tmp=a[0];
		for(int i=1;i<m;i++){
			tmp=(tmp&a[i]);
		}
		ans=max(ans,tmp);
	}while(next_permutation(a.begin(),a.end()));
	cout<<ans;
	//bjy
}
