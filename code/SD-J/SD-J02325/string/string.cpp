#include<bits/stdc++.h>
using namespace std;
string s;
char x,t;
long long n,q,ans,p=-1;
bool w=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>q>>x;
		for(int j=0;j<q;j++){
			p++;
			s[p]=x;
		}
		if(i==0){
			t=x;
		}else{
			if(t!=x){
				w=false;
			} 
		}
	}
	//cout<<endl<<s;
	if(w){
		cout<<0;
		return 0;
	}
	w=true;
	for(int i=n-1;i>=(n+1)/2-1;i--){
		if(s[i]!=s[n+1-i]){
			w=false;
			ans++;
		}
	} 
	if(w){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
 
