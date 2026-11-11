#include <bits/stdc++.h>
using namespace std;
	int a,b,c,d=0,n=1;
	string s,m,x;
int main(){
		freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b>>s;
		c+=b;
		if(i==1){
			x=s;
		}

		if(n==1&&s==x){
			n=1;
		}
		else{
			n=0;
		}
		for(int i=1;i<=b;i++){
			m=m+s;
		}
		
	}
	if(n==1){
		cout<<"0";
		//ut<<"yes";
		return 0;
	}
//out<<m[0]<<' '<<m[c-1]<<' '<<m[c-2]<<' ';
//f(c%2==0){
		
		for (int i=0;i<c/2;i++){
			if (m[i]!=m[c-1-i]){
				d++;
			}
		}

	cout<<d;
	//cin>>a>>b;
//out<<m;
	//ceil floor sort sprt pow 
	return 0;
} 
