#include<bits/stdc++.h>
using namespace std;	
int n,ar[200005]={},cnt=0,sum=0,flag=1;
string s[200005],s1,s2,s3;
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i]>>s[i];
		sum+=ar[i];
	}
	for(int i=1;i<n;i++){
		if(s[i]!=s[i+1]){
			flag=0;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ar[i];j++){
			s3+=s[i];
		}
	}
	for(int i=0;i<sum/2;i++){
		s1+=s3[i];
	}
	for(int i=sum;i>=sum-sum/2;i--){
		s2+=s3[i];
	}
	for(int i=1;i<=sum/2;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
}
