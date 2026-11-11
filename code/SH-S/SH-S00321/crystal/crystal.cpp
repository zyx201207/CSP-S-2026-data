#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,k=1,an=0;
	long long m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		k=1;
		ans=0;
		for(int j=i-1;j>=0;j--){
		ans+=(a[i]-a[j]);
		if(ans>m){
		break;	
	}
		k++;
		
		}
		an=max(an,k);
	}
	cout<<an;
	return 0;
}
