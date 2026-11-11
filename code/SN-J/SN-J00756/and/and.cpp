//SN-J00756 程谟然 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long a[200005]={};
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long corn=0;
	for(long long i=n;i>=1;i--){
		corn++;
		if(corn==m){
			long long h=a[i]&a[i+1];
			cout<<h;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
