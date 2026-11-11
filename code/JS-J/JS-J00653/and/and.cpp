#include<bits/stdc++.h>
using namespace std;
int cmp(vector<int>&a,int n,int ans,int m){
		for(int i=1;i<=m;i++){
			if(n==1){
				 ans=max(a[i],a[i+1]);
				 return ans;
			}
			else{
				if(a[i]/n!=1 || a[i]/n!=0){
				ans=(a[i]-a[i]/n)%n;	
				}
				else
				ans=a[i]%n;
			}
		}
		return ans;
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  m,n;
	cin>>m>>n;
	vector<int> a(m);
	int ans=12;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		if(m==1){
			ans=a[1];
			cout<<ans;
			return 0;
		}
	}
	ans=cmp(a,ans,n,m);
	cout<<ans;
	fclose(stdin);
	 fclose(stdout);
	return 0;
}
