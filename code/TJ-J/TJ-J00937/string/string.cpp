#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,total=0;
	string s="";
	scanf("%d",&n);
	while(n!=0){
		int a,c;
		scanf("%d",&a);
		scanf("%s",&c);
		for(int i=1;i<=a;i++){
			s+=c;
		}
		n--;
	}
	string t=s;
	reverse(s.begin(),s.end());
	if(s==t){
		cout<<0;
		return 0;
	} 
	else{
		for(int i=0;i<t.length();i++){
			if(s[i]!=t[i]){
				total++;
			}
		}
	}
	cout<<total/2;
	return 0;
}
