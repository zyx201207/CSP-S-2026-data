#include<bits/stdc++.h>
using namespace std;
long long hui[100000000],left[50000000],right[50000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a;
	char c;
	long long m=1;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			hui[m]=c;
			m++;
		} 
	}
	m=m-1;
	if(n==1){
		cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=m/2;i++){
		int l=hui[i],r=hui[m-i+1];
		if(l!=r){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
