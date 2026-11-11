#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s=""; 
	int sum=0;
	for(int i=0;i<n;i++){
		long long num;
		char c;
		scanf("%lld",&num);
		cin>>c;
		sum+=num;
		while(num--){
			s+=c;
		}
	}
	if(sum==1){
		cout<<0;
		return 0;
	}
	//cout<<s;
	int l=s.length();
	int ans=0;
	string neww1="";
	string neww2="";
	if(l%2==0){
		for(int i=0;i<=l/2-1;i++){
			neww1+=s[i];
		}
		for(int i=l-1;i>l/2-1;i--){
			neww2+=s[i];
		}
	}
	else{
		for(int i=0;i<l/2;i++){
			neww1+=s[i];
		}
		for(int i=l-1;i>l/2;i--){
			neww2+=s[i];
		}
	}
	int ll=neww1.length();
	for(int i=0;i<ll;i++){
		if(neww1[i]!=neww2[i]){
			ans++;
		}
	}
	cout<<ans;
}
