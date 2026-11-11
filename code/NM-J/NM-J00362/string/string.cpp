#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long int sum=0,ans=0;
	string s;
	for(int i=1;i<=n;i++){
		int lin;
		cin>>lin;
		sum+=lin;
		string aa;
		cin>>aa;
		//cout<<"yunxingle"<<endl;
		for(int i=1;i<=lin;i++)
		{
			s+=aa;
		}
		
	}
//	cout<<s<<endl;
	for(int i=0;i<sum/2;i++){
		
		int j=sum-i-1;
		//cout<<j<<endl;
		if(s[i]!=s[j]){
	//	cout<<i<<" "<<j<<endl;
		ans++;
		
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
