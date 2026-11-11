#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n,k=0,d=0,p=0;
	string s,s2,s3;
	cin>>n;
	long long a[100005];
	char b[100005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s[k]=b[i];
			k++;
		}
		
	}
	//cout<<k<<endl;
	//for(int i=0;i<k;i++){
	//	cout<<s[i];
	//}
	//cout<<endl;
	for(int i=0;i<k/2;i++){
		s2[i]=s[i];
	}
	//for(int i=0;i<k/2;i++){
	//	cout<<s2[i];
	//}
	//cout<<endl;
	for(int i=-1;i<k/2;i++){
		s3[i]=s[k-i-1];
	}
	//for(int i=0;i<k/2;i++){
	//	cout<<s3[i];
	//}
	//cout<<endl<<"s3:"<<s3[0]<<"s2:"<<s2[0]<<endl;
	//if(s2[0]==s3[0]){
	//	cout<<"yes";
	//}
	p=0;
	for(int i=0;i<k/2;i++){
		if(s3[i]!=s2[i]){
			p++;
		}
	}
	cout<<p;
	return 0;
}