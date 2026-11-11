#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt=0,a,;
int main(){
	feropen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i=0;i<t;i++){
		int x[n],y[n];
		for(int j=0;j<n;j++){
			cin >> x[j];
		}
		a = d/(x[1]-x[0]);
		if(a=3){
			cnt++;
		}
		if(a<3){
			continue;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
}
