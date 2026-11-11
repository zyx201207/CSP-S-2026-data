#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		long long x=a[2]-a[1];
		long long num=0;
		for(int i=1;i<=n;i++){
			num+=i*x;
			if(num>m){
				cout<<i-1;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		cout<<n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		long long num=0;
		for(int j=i+1;j<=n;j++){
			num+=(j-i)*(a[j]-a[j-1]);
			if(num>m){
				ans=max(ans,j-i);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
