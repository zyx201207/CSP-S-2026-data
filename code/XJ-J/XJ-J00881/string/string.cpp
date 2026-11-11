#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c,bottle;
	string s1,s2,s3;
	bool kaisu;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s1+=c;
		}
		c=' ';
	}
	cout<<s1<<endl;
	bottle=s1[0];
	for(int i=0;i<s1.size();i++){
		s2[i]=s1[i];
	}
	for(int i=s1.size();i>0;i--){
		s3[i]=s1[i];
	}
	if(s2==s3){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}