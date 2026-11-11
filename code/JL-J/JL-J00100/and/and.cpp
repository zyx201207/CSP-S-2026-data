#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int ans=0;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			if(a>=ans) ans=a;
		}
		cout<<ans;
	}
	if(m==n){
		int ans=0;
		cin>>ans;
		for (int i=1;i<n;i++){
			int a;
			cin>>a;
			ans=ans&a;
		}
		cout<<ans;
	}
	if(m==2){
		vector<int> a(n);
		int ans=-1;
		for (int i=0;i<n;i++){
			cin>>a[i];
			cout<<a[i]<<endl;
		}
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				if((a[i]&a[j])>=ans) ans=a[i]&a[j];
			}
		}
		cout<<ans;
	}
	return 0;
}
