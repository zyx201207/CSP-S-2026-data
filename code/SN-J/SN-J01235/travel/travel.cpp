#include <bits/stdc++.h> 
using namespace std;
int n[5],s1[10];
char s2[10];
int main(){
	freopen("traver.in","r",stdin);
	freopen("traver.out","w",stdout);
	for (int i=1;i<=2;i++){
		cin>>n[i];
		cin>>s1[i];
		cin>>s2[i];
	}
	if (n[1]==n[2]){
		cout<<1;
		if (s1[1]==s1[2]){
			cout<<1;
			if (s2[1]>='A'&&s2[1]<='C'&&s2[2]>='A'&&s2[2]<='c')
			{
				cout<<1;
				
			}else{
				if (s2[1]>='D'&&s2[1]<='F'&&s2[2]>='D'&&s2[2]<='F'){
					cout<<1;
			    }
				else{
				    cout<<0;	
				}
				}
			if (s2[1]-1==s2[1]||s2[1]+1==s2[1])
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
	    }
		else{
		    cout<<0;
	    }
	}
	else{
		cout<<0;
	}
	
	return 0;
}
