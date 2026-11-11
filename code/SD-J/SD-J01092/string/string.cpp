#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[2000005];
vector <char> ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	bool tag=1;
	long long sum;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
		if(i>=2&&s[i]!=s[i-1]){
			tag=0;
		}
	}
	if(tag){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			ss.push_back(s[i]);
		}
	}
	long long ans=0;
	int len=sum/2;
	for(int i=0;i<len;i++){
		if(ss[i]!=ss[sum-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
