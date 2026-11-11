#include<bits/stdc++.h>
#include<string>
using namespace std;
int a,l[200000000],num,si;
string s[10000000],str; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>l[i]>>s[i];
		si=si+l[i];
	}
	si=si-1;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=l[i];j++){
			str=str+s[i];
			}
	}
	for(int i=0;i<si/2;i++){
		if(str[i]!=str[si-i]){
				num++;
				
			} 
		
	}
	cout<<num;
	return 0;
}
// 3 5 a 5 b 5 c
