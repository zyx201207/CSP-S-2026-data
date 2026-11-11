#include<bits/stdc++.h>
using namespace std;
int a[200005];
int MAX(){
	int ret=0,ri;
	for(int i=0;i<200005;i++){
		if(a[i]>ret){
			ret=a[i];
			ri=i;
		}
	}
	a[ri]=0;
	return ret;
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int b[200005];
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<m;i++){
		b[i]=MAX(); 
	}
	int ans=b[0];
	for(int i=1;i<m;i++){
		ans=ans&b[i];
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
