#include<bits/stdc++.h>
using namespace std;

int main(){
		
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	

	int n;
	cin>>n;
	



	
	if(n==1){
		cout<<0;
		return 0;
	}
	
	
	
	
	if(n==2){
		string a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b!=d)
			cout<<min(a,c);
		else
			cout<<0;
		return 0;
	}	
	
	
	
	
	
	
	
	
	
	
	
	
		
	int he=0;
	int a[n+1]={};
	char b[n+1]={};
	vector<char> str;
	str.push_back(0);
	for(int i=1;i<=n;i++){	
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
			str.push_back(b[i]);
	}	
	
	int cd=str.size();


	if(cd%2==0){
		for(int i=1;i<=(cd/2);i++){
			if(str[i]!=str[cd-i])
				he++;			
		}		
	}
	else{
		for(int i=1;i<=((cd-1)/2);i++){
			if(str[i]!=str[cd-i])
				he++;			
		}	
	}	
	
	cout<<he;
	




	fclose(stdin);
	fclose(stdout);
		
	return 0;
}
