#include<bits/stdc++.h>
using namespace std;
int a[1001];
int c[1002];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,h,sum=0;
	bool m=1;
	cin>>n;
	string a,c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		h=c[1];
		if(c[i]==h){
			m=true;
		}else m=false;
		break;
	}
	if(m=1){
		cout<<"0";
	}
	 for(int i=1; i<=n;i++){
	 	if(a[i]%2==0){
	 		
		 }
	 }
	 return 0;
}


