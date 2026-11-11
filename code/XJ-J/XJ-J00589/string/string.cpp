#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	int p;
	if(s.size()%2==0){
		p=s.size()/2;
	}else{
		p=s.size()/2+1;
	}
	for(int i=0;i<p;i++){
		x[i]=s[i];
	}
	int j=p-1;
	if(s.size()%2==0){
		for(int i=p;i<s.size();i++){
			if(s[i]!=x[j]){
				sum++;
			}
			j--;
		}
		cout<<sum;
	}else{
		for(int i=p-1;i<s.size();i++){
			if(s[i]!=x[j]){
				sum++;
			}
			j--;
		}	
		cout<<sum;
	}
	return 0;
}