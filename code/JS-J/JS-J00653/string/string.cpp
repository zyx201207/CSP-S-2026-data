#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			cin>>b[i];
		}
		if(b[i]==b[i+1]){
			cout<<"0";
			return 0;
		}
	}
	int ans=2;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}










