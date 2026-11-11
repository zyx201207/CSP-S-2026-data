#include<iostream>
using namespace std;
int n,m,len,sum;
string a,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w".stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>a;
		for(int i=0;i<m;i++){
			t+=a;
			len++;
		}
	}
	for(int i=0;i<len;i++){
		if(t[i]!=t[len-i]){
			t[i]=t[len-i];
			sum++;
		} 
	}
	cout<<sum;
	return 0;
}
