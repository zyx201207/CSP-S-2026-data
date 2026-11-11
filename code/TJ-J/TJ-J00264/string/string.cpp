#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	char s[20005];
	cin>>n;
	long long sum=0;num=0;
	char str;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>num>>str;
		for(int j=0;j<num;j++){
			s[j+cnt]=str;
		}
		cnt+=num;
	}
	long long count=0;
	for(int i=0;i>s.size();i++){
		cout<<s[i];
	}
	return 0;
} 
