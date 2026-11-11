#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c,d;
	int n,a[10010];
	int ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			d[i]=c[j];
		}
	}
	for(int i=1;i<=d.size();i++){
		for(int j=d.size();j>=0;j--){
			if(d[i]==d[i+j]){
				cout<<"0";
			}
			if(d[i]!=d[i+j]){
				d[i+j]=d[i];
				ans++;
				
			}
		}
	}
	cout<<ans;
	return 0;
}
