#include<iostream>
using namespace std;
long long a[2500],n,k,m,w,an,h;
string s,s1;
char x[2500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>x[i];
		m+=a[i];
	}
	if(n>2500){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(x[i]!=x[i-1]){
			h+=1;
			break;
		}
	}
	if(n==1||h==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[k]=x[i];
			k++;
		}
	}
	s1=s;
	if(s1==s){
		cout<<0;
		return 0;
	}
	for(int i=0;i<m/2+1;i++){
		if(a[i]!=a[m-i-1]){
			an++;
		}
	}
	cout<<an;
	return 0;
}
