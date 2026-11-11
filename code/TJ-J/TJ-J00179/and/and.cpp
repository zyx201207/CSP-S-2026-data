#include<bits/stdc++.h>
using namespace std;
int s[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,num=0;
	int sum=12345678;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(sum>s[i])sum=s[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]>sum&&(s[i]<=s[i+1]||s[i]<=s[i-1]))num=s[i];
	}
	cout<<num;
}
