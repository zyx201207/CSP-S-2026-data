#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[10001]={},b[10001]={};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i]>>b[i];
		}
		cout<<o<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
