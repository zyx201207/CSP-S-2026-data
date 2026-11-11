#include<bits/stdc++.h>
using namespace std;
int s1;string t1,n1={};
string x(string d){
		while(t1="0"){
		
				for(int i=0;i<d.size();i++){
			if(d[i]<2&&s1==0){
				s1+=(d[i]-'0')+(d[i+1]-'0');
				i++;
			}else{
				s1+=(d[i]-'0');
			}t1+=(s1/2)+'0';
			s1=0;
			if(s1%2==1){
				s1+=10;			
			}
		}x(t1);
		if(s1!=0){
			n1+='1';
		}else{
			n1+='0';
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m=0;
	string a[2000001];
	string b[2000001];
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[0];
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}