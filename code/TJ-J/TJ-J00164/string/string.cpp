#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int c[10000];
	char a[10000];
	for(int i=1;i<=n;i++){
		cin>>c[i]>>a[i];
		a[i]-='0';
	}
	for(int i=1;i<=n;i++){
		if(n==1){
			cout<<"0";
			break;
		}else if(n==2 && a[i]==a[i+1]){
				cout<<"0";
				break;
			}else{
				cout<<"1";
				return 0;
			}	
		}
	return 0;
}
