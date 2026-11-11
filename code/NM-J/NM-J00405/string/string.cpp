#include<bits/stdc++.h>
using namespace std;
int n;int sum;
int a[200005];
string c[200005];
int ans;
string jh;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			jh+=c[i];
		}
		sum+=a[i];
	}
	for(int i=1;i<=sum/2;i++){
		if(jh[i]!=jh[sum+1-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

