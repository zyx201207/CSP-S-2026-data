#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	int n,idx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int nu;
		char c;
		scanf("%d",&nu);
		cin>>c;
		sum+=nu;
		for(int i=1;i<=nu;i++){
			s[idx]=c;
			idx++;
		}
	}
	long long ans=0;
	for(int i=0;i<=(sum-1)/2;i++){
		if(s[i]!=s[sum-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
