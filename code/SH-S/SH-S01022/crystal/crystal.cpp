#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,sum=1;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(m>=i*ans){
			m-=i*ans;
			sum++;
		}
		else{
			cout<<sum;
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
