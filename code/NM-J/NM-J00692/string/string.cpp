#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int x;
		char y;
		cin>>x>>y;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j<=x/y.size()){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
