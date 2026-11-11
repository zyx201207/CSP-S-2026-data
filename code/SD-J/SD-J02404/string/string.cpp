#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0,sum=0;
char d;
string s="",ss="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>d;
		for(int j=0;j<a;j++){
			s+=d;
			ans++;
		}
	}
	for(int i=ans-1;i>=0;i--){
		ss+=s[i];
	}
	for(int i=0;i<ans;i++){
		if(s[i]!=ss[i]){
			sum++;
		}
	}
	sum=sum/2;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
