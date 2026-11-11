#include<iostream>
using namespace std;
string m,n;
int cont;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n1,n2;
	cin>>n1;
	if(n1==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n1;i++){
		cin>>n2>>n;
		for(int j=1;j<=n2;j++){
			m+=n;
		}
	}
	for(int i=0;i<m.size();i++){
	    if(m[i]!=m[m.size()-1-i]){
	    	cont++;
	    	m[m.size()-i-1]=m[i];
		}
	}
	cout<<cont;
	fclose(stdin);
	fclose(stdout);
}
