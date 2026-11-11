#include<bits/stdc++.h>

using namespace std;
long long n,m,ans=0,a[200005],b;
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);//ะก->ด๓ 
	for(int i=0;i<m;i++){
		if(i==0){
			ans=a[n-1-i];
		}
		else{
			ans&=a[n-1-i];
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
