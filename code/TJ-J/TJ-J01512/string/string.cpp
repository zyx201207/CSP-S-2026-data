#include<bits/stdc++.h>
using namespace std;
pair<int,char>a[1000001];
int n;
long long ans;
int l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(l<r){
		int mins=min(a[l].first,a[r].first);
		a[l].first-=mins;
		a[r].first-=mins;
		if(a[l].second!=a[r].second){
			ans+=mins;
		}
		if(a[l].first==0){
			l++;
		}
		if(a[r].first==0){
			r--;
		}
	}
	cout<<ans;
} 
