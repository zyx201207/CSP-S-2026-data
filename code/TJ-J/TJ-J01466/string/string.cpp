#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n;
	string s;
	cin>>n;
	string c;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=0;j<a[i];j++){
			s[i]=c[i];
		}
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	if(n<=2){
		int sum=0;
		sum=min(a[0],a[n])-1;
		if(sum==0){
			cout<<1;
		}
		cout<<sum;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=a[i]; 
	}
	int num=0;
	for(int i=0;i<(ans-1)/2;i++){
		if(s[i]!=s[ans-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
} 
