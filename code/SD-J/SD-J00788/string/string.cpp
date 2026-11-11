#include<bits/stdc++.h>
using namespace std;
int main(){
	long long i,ans=0,ans2=0,ans3=0,a=0;
	cin>>i;
	long long n[i];
	char c[i];
	for(int j=0;j<i;j++){
		cin>>n[j]>>c[j];
		ans+=1;
		ans2+=n[j];
	}
	string s[ans2];
	for(int j=0;j<ans;j++){
		for(int m=ans3;m<ans3+n[j];m++){
			s[m]=c[j];
		}
		ans3+=n[j];
		
	}
	//for(int j=0;j<ans2;j++){
	//	cout<<s[j];
	//}
	string neo[ans2];
	long long m=ans2-1;
	//cout<<ans2;
	for(int j=0;j<ans2;j++){
		neo[m]=s[j];
		//cout<<m;
		m--;
		
	}
	for(int j=0;j<ans2/2;j++){
		if(neo[j]!=s[j])a++;
	}
	cout<<a;
	
	return 0;
}//
