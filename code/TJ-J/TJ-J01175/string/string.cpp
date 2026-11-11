#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,mid,ans;
char s[1000000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int ai;
		string ci;
		cin>>ai>>ci;
		for(int u=1;u<=ai;u++){
			for(int j=1;j<=ci.size();j++){
				sum++;
				s[sum]=ci[j-1];
			}
		}	
	}
	mid=sum/2;
	long long j=mid+1;
	for(int i=1;i<=mid;i++){
		if(s[i]!=s[j]){
			ans++;
		}
		j++;
	}
	cout<<ans;
	return 0;
} 
