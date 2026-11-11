#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500001]={},cnt=1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}*/
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])*cnt<=m){
			m-=(a[i]-a[i-1])*cnt;
			cnt++;
			//cout<<a[i]<<' '<<a[i-1]<<' '<<a[i]-a[i-1]<<' ';
		}else{
			break;
		}
	}
	cout<<cnt;
} 