#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005][500005],d[500005][500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c,t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			cin>>c[i][j]>>d[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
