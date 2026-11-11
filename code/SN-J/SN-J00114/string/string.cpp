#include <bits/stdc++.h>
using namespace std;
struct hw{
	long long a;
	char c;
}h[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>h[i].a>>h[i].c;
	}
	string s="";
	for (int i=0;i<n;i++){
		for (int j=0;j<h[i].a;j++){
			s+=h[i].c;
		}
	}
	long long ans=s.size();
	long long sum=0;
	if (ans%2==0){
		for (int i=ans/2;i<=ans;i++){
			for (int j=1;j<ans/2;j++){
				if (s[i]!=s[i-j]){
					sum++;
				}
			}
		}
		cout<<sum;
	}
	else if (ans%2==1){
		for (int i=(ans-1)/2;i<=ans;i++){
			for (int j=1;j<(ans-1)/2;j++){
				if (s[i]!=s[i-j]){
					sum++;
				}
			}
		}
		cout<<sum-1;
	}
	return 0;
}
