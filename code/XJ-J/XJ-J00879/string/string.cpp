#include<bits/stdc++.h>
using namespace std;
int str(string a){
	long long time=0;
	if(a.size()%2==0){
		for(int i=0;i<a.size()/2;i++){
			if(a[i]!=a[a.size()-1-i]){
				time++;
			}
		}
	}else{
		for(int i=0;i<(a.size()-1)/2;i++){
			if(a[i]!=a[a.size()-1-i]){
				time++;
			}
		}
	}
	return time;
}
string a;
long long b,n;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b>>c;
		for(int j=0;j<b;j++){
			a+=c;
		}
	}
	cout<<str(a);
	return 0;
}