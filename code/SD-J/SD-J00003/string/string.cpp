#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out", "w",stdout);
	string a;
	char st;
	int n,le,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>le>>st;
		for(int j=1;j<=le;j++){
			a+=st;
		}
	}
//	cout<<a.size()<<" ";
	for(int i=0;i<=a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
	}
