#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a.begin(),a.end());
	int idx=(n)/2;
	vector<int> ndeg(n); //NeedEnerge
	for(int i=0;i<n;++i){
		ndeg[i]=abs(a[idx]-a[i]);
	}
	sort(ndeg.begin(),ndeg.end());
	for(int i=0;i<n;++i){
//		cout<<ndeg[i]<<" "; 
		if(m>=ndeg[i]){
			m-=ndeg[i];
		    ndeg[i]=0;
		}		
	}
	sort(ndeg.begin(),ndeg.end());
	int ans=0; 
	for(int i=0;i<n;++i){
		if(ndeg[i]==0) ++ans;
//		cout<<ndeg[i]<<" "; 
	} 
	cout<<endl;
	cout<<ans;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/