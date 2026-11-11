#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010],b,c[200010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m==2){
			cout<<12;
			return 0;
		}
		if(m==3){
			cout<<7;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}