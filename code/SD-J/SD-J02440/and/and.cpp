#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200010],cnt=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}
	else{
		sort(a,a+1+n);
		maxx=a[n];
		for(int i=1;i<m;i++){
			maxx=maxx&a[n-cnt];
			cnt++;
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
