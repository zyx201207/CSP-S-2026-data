#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
char c[100005];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	string sum="";
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++) sum+=c[i];
	}
	int db=0;
	for(int i=0;i<sum.size();i++){
		if(sum[i]!=sum[sum.size()-i-1]) db++;
	}
	cout<<db/2;
	return 0;
}
