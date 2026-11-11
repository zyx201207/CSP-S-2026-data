#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200005],maxx=-0x3f3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//cout<<a[i]<<" "<<a[j]<<endl;
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
