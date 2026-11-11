#include<bits/stdc++.h>
using namespace std;
int n;
int m;
string paidui;
string jieguo;
int a=0;
int main(){
	cin>>n,m;
	cin>>pai;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=0;i<=m;i++){
		paidui=paidui+pai[i];
		for(int x=i+1;x<=m;x++){
				for(int j=0;j<=n;j++){
					if(paodui[i]==paidui[j]){
						a++;
			    	}
			    	cout<<a;
			    	a=0;
				}
		}
	}
	return 0;
}
