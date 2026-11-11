#include<bits/stdc++.h>
using namespace std;
bool pd(string a){
	string b="";
	for(int i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	if(a==b){
		return 1;
	}
	else{
		return 0;
	}
}
//string th(string a,int i,char b){
//	string c="";
//	for(int ii=0;ii<a.size();i++){
//		if(ii==i){
//			c+=b;
//		}
//		else{
//			c+=a[ii];
//		}
//	}
//	return c;
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a="";
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a1;
		char c;
		cin>>a1>>c;
		for(int i=1;i<=a1;i++){
			a+=c;
		}
		m+=a1;
	}
	if(pd(a)){
		cout<<"0";
		return 0;
	} 
	int mm=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==a[m-i]){
			continue;
		}
		if(pd(a)){
			break;
		}
		a[i]=a[m-i];
		mm++;
	}
	cout<<mm;
	return 0;
} 
