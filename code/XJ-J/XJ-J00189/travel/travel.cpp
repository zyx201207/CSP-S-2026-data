#include<bits/stdc++.h>
using namespace std;
int main()
{
	//preopen("stdin.travel","r",stdin);
	//preopen("stdout.travel","w",stdout);
	string s,t,x,y;
	cin>>s>>t>>x>>y;
	int sum=0;
	for(int a=0;a<x.size();a++){
		for(int b=0;b<y.size();b++){
			if(x[a]==y[b]){
		sum+=1;
		if(sum==2)cout<<"1";
		else{
		 cout<<"0000";
		 return 0;
	}
		for(int i=0;i<2;i++){
			cin>>s[i]>>t[i];
				if(s[i]==t[i]){
					cout<<"1";
				}else cout<<"0";
			}
		}
		}
		
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
 } 
