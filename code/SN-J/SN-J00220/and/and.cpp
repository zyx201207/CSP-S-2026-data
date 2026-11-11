#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a ,b,c[1000];
	cin>>a>>b;
	for(int j=0;j<=a;j++){
			cin>>c[j];
			int d=c[j];
			while(d!=0) {
				cout<<d%2;
				d/=2;
			}
			cout<<endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
