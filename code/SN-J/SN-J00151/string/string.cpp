#include<bits/stdc++.h>
using namespace std;
int n,ans,l,id;
string s;
string b;
bool camp(){
	for(int i=0;i<l;i++){
		if(s[i]!=b[i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		string y;
		cin>>y;
		for(int i=0;i<x;i++){
			s+=y;
			l++;
		}
	}
	for(int i=l-1;i>=0;i--){
		b[id]=s[i];
		id++;
	}
	if(camp()){
		cout<<"0";
		return 0;
	}
	int mid=l/2;
	if(l%2==1){
		for(int i=0;i<mid;i++){
			for(int j=l-1;j>mid;j--){
				if(s[i]!=s[j]){
					ans++;
				}
			}
		}	
	}else{
		for(int i=0;i<mid;i++){
			for(int j=n-1;j>=mid;j--){
				if(s[i]!=s[j]){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
