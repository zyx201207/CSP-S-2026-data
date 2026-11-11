#include<bits/stdc++.h>
using namespace std;
int s[100000005];
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		char a;
		cin>>a;
		for(int j=i;j<i+x;j++){
			s[j]=a;
		}
		i+=x-1;
		n+=x-1;
	}
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]){
			//cout<<i<<' '<<n+1-i<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
