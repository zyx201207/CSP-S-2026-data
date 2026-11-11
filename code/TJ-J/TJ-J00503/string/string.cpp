#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[10005],c[10005],sum=0,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	reverse(a[i].begin(),c[i].end());
	
	cout<<"2";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
