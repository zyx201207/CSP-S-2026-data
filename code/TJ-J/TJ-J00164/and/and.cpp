#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,max=0,c[100000];
	cin>>n>>m;
	if(m==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];	
	}
	for(int i=1;i<=n;i++){
		if(m==2){
			if((c[i]&&c[i+1])>max){
				max=(c[i]&&c[i+1]);
			}
		}
	}
	cout<<max;
	return 0;
}
