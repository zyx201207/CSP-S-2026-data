#include<bits/stdc++.h>

using namespace std;
long long n,m,a[500005],ans=1; 
int main(){
	freopen(crystal.in,"r",stdin);
	freopen(crystal.out,"w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);//ะก->ด๓
	for(int i=0;i<n&&m>0;i++){
		if(i!=n-1&&m>=a[i+1]-a[i]){
			m-=a[i+1]-a[i];
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
