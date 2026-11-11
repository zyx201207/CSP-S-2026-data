#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500001],b[500001];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=b[i-1]+i*(a[i]-a[i-1]);
	}long long ans=0;
	for(int i=0;i+ans<n;i++){
		if(b[i+(ans)]-b[i]-i*(a[i+(ans)]-a[i])<=m){
			ans++;
			i--;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
