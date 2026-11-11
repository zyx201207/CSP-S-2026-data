#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s=" ";
	int l=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		l+=x;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	int sum=0;
//	cout<<l<<endl;
	for(int i=1;i<=l/2;i++){
//		cout<<s[i]<<" "<<s[l-i+1]<<endl; 
		if(s[l-i+1]!=s[i]){
			s[l+1-i]=s[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

