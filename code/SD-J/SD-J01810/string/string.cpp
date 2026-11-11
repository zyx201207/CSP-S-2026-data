#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char c;
	string s;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	
	long long i=0,j=s.size()-1;
	long long ans=0;
	
	while(i!=j&&i<j){
		if(s[i]!=s[j]){
			ans++;
		}
		//cout<<endl<<"...."<<s<<i<<j<<endl;
		i++;
		j--;
	}
	

	cout<<ans<<endl;
	
	return 0;
}
