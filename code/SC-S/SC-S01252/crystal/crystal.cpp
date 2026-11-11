#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long a[500050]={0};

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int fl=1;
	long long d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])!=d){
			fl=0;
		}
	}
	
	long long ans=0;
	for(int i=n;i>=ans;i--){
		long long b=a[i];
		long long cur=0;
		long long mm=m;
		while(mm>=b-a[i-cur]){
			mm-=(b-a[i-cur]);
			cur++;
		}
		
		ans=max(ans,cur);
		if((fl==1)&&(ans)){
			break;
		}
	}
	
	cout<<ans;
	
	
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}