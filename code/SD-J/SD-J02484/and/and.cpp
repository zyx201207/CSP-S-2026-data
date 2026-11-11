#include<bits/stdc++.h>

using namespace std;
long long n,m;
long long a[200010];
long long ma=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}





























/*#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[200010];
int ma=INT_MIN,mb=INT_MIN+1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<=n;j++){
			ma=max(ma,a[j]);
		}
		cout<<ma;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>ma){
			mb=ma;
			ma=a[i];
		}else if(a[i]>mb&&a[i]<=ma){
			mb=a[i];
		}
	} 
	cout<<ma and mb;
	return 0;
}*/
