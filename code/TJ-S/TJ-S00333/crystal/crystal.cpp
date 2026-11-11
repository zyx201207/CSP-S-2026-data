#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);
	int cnt=0,big=-1,ji=0,lin=0,m1=m;
	for(int i=1;i<=a[n-1];i++){
		m=m1;
		cnt=0;
		for(int j=n-1;j>=0;j--) {
			if(a[j]<=i) {
				ji=j;
				break;
			}
		}
		for(int j=ji;j>=0;j--){
			lin=i-a[j];
			if(m-lin>=0){
				m=m-lin;
				cnt++;
			}else break;
		}
		if(cnt>big)big=cnt;
	}
	cout << big;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
