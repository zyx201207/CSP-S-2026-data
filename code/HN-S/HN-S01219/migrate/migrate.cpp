#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,s,cnt=0,cnt1=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]>=d){
			cnt++;
		}
	for(int j=1;j<=n;j++){
		if(a[j]-a[j-1]>=d){
			cnt1++;
		}
	}
		if(cnt==cnt1){
			s++;
		}
	}
	cout<<s;
	return 0;
}
