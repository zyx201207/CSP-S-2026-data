#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long a[N];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	long long ans=a[1];
	bool vis=0;
	for(int i=1;i<=m;i++){
		bool f=1;
		for(int j=30;j>=1;j--){
			if(a[i]==1<<j){ f=0; break;}
		}
		if(f==0){
			m++;
			if(!vis) ans=a[i+1];
			continue;
		}
		else{
			vis=1;
			ans=ans&a[i];
		}
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
