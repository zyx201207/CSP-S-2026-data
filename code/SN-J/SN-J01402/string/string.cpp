#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long hui[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long aa;
		string ss;
		cin>>aa>>ss;
		int b=ss[0]-'a';
		for(long long j=ans;j<=ans+aa;j++){
			hui[j]=b;
		}
		ans+=aa;
	}
	long long cnt=0;
	for(long long j=1,k=ans;k>=j;k--,j++){
		if(hui[j]!=hui[k]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
