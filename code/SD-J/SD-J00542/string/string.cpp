#include<bits/stdc++.h>
using namespace std;
long long a[20005];
char x[20005];
int main(){
	string s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>x[i];
		
	}
	cout<<s;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s+=x[i];
		}	
	}
	s+=x[1];
	cout<<s;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(x[1]!=x[2]){
			cout<<min(a[1],a[2]);
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
