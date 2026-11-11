#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10000000009];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];	
	}
	sort(a,a+n);
	int sum=1;
	for(int i=0;i<=n;++i){
		int	k=a[i]-a[i-1];
		if(k>m){
		 cout<<"1";
		}else{
		      m-=k;
		      sum+=1;
		}
		}
	cout<<sum;
	return 0;
}
