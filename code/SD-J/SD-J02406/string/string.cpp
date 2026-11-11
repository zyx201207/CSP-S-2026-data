#include<bits/stdc++.h>
using namespace std;
int n,v,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]==1){
		    s+=c[i];	
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				v++;
			}
		}
	}else{
		for(int i=0;i<(s.size()+1)/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				v++;
			}
		}
	}
	cout<<v;
	return 0;
} 
