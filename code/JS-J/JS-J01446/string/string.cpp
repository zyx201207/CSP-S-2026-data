#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len=0;
	string a;
	for(int i=0;i<n;i++){
		int nn;
		char c;
		cin>>nn>>c;
		for(int j=0;j<nn;j++)a+=c;
		len+=nn;
	}
	int ans=0;
	for(int i=1;i*2<=len;i++){
		if(a[i-1]!=a[len-i])ans++;
	}
	cout<<ans;
	return 0;
}
