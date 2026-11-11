#include<bits/stdc++.h>
using namespace std;
int n;
int num[200010];
char c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}for(int i=1;i<=n;i++){
		if(i>n+1-i)break;
		if(!(num[i]==num[n+1-i]&&c[i]==c[n+1-i])){
			ans+=max(num[i],num[n+1-i]);
			//cout<<num[i]<<"\n";
		}
	}cout<<ans;
	return 0;
} 
