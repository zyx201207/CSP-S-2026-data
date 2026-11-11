#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long int sum=0,ans=0;
	cin >> n;
	string s;
	for(int i =1;i<=n;i++){
		long long int x;
		char a;
		cin >> x >> a;
		sum+=x;
		for(long long int j=1;j<=x;j++){
			s+=a;
		}
	}
	long long int z=sum/2;
	
	if(sum%2==0){
		for(long long int i =z;i<=sum-1;i++){
			if(s[sum-1-i]!=s[i]){
				ans++;
			}
		}
	}else{
		z=z+1;
		for(long long int i =z;i<=sum-1;i++){
			if(s[i]!=s[sum-1-i]){
				ans++;
			}
		}
	}
	cout <<ans;
	return 0;
}
