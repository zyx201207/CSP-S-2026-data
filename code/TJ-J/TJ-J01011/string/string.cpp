#include<bits/stdc++.h>
using namespace std;
int x[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x[i]>>c[i];
	}
	unsigned long long ans=0;
	int i=1;
	int j=t;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(x[i],x[j]);
		}
		if(x[i]>x[j]){
			x[i]-=x[j];
			j--;
		}
		else if(x[i]<x[j]){
			x[j]-=x[i];
			i++;
		}
		else{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
