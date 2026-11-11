#include <bits/stdc++.h> 
using namespace std;

string s;
int n,cnt[1000005],ans;
long long sum;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		string m;
		cin >>x >> m;
		sum+=x;
		for(int i=0;i<x;i++){
			s+=m;
		}
	}
	int sum2=sum/2;
	for(int i=sum-1;i>=sum2;i--){
		if(s[i]!=s[sum+1-i]){
			ans++;
		}
		
	}
	cout << ans;
	return 0;
}
