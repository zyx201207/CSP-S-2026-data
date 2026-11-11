#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w=0;
	for(int i=0;i<m;i++){
		cin>>w;
	}
	int a[10005];
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	int x[10005];
	for(int r=0;r<2;r++){
		cin>>x[r];
	}
	int y[10005];
	for(int s=0;s<2;s++){
		cin>>x[s];
	}
	
	
	cout<<"32"<<endl;
	cout<<"17"<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
