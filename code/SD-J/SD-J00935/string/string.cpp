#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a;
		cin>>c;
		for(int g=1;g<=a;g++){
			s+=c;
		}
	}
	int d=s.size()-1,ans=0;
	//cout<<endl<<s<<"  "<<d<<"//"<<ans<<endl;
	int o=s.size()/2;
	//cout<<"  "<<o<<"  " ;
	for(int i=0;i<=s.size()/2;i++){
		
		if(s[i]!=s[d]){
			ans++;
			//cout<<"i:"<<i;
			//cout<<"ans:"<<ans;
			//cout<<"d:"<<d;
		}
		d--;
	}
	cout<<ans;
	return 0;
}
