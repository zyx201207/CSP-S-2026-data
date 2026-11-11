#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,h;
	string b;
	cin>>n;
	string c="";
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		for(int j=1;j<=a;j++){
			c+=b;
		}
	}
	int js=0;
	if(b.size()%2==0){
		int l=c.size()/2;
		string q=c.erase(l+1,c.size()/2);
		string w=c.erase(1,l);
		reverse(w.begin(),w.end());
		for(int i=1;i<=c.size()/2;i++){
			if(q[i]!=w[i]){
				js++;
			}
		}
	}
	cout<<js;
	if(c.size()%2==1){
		int l=c.size()/2;
		string q=c.erase(l,c.size()/2+1);
		string w=c.erase(1,l+1);
		reverse(w.begin(),w.end());
		for(int i=1;i<=l+2;i++){
			if(q[i]!=w[i]){
				js++;
			}
		}
	}
	cout<<js;
	return 0;
}
