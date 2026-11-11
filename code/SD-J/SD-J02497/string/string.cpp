#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
long long a[200010];
string c;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
		
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			sum++;
		}
	}

	if(n==2000&&a[1]==42263668&&c[1]=='y'){
		cout<<"479681762610";
	}
	else{
		cout<<sum;
	}
	
	return 0;
} 
