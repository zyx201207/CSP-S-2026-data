//高易 延安育英中学 SN-J00695 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;string b,zon=" ",zonn=" ";long long cnt=0,q=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			zon+=b;
		}
		
	}
	for(int i=zon.length();i>=0;i--){
		zonn+=zon[i];
	}
	if(zon==zonn){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=(zon.length()-1)/2;i++){
				if(zon[i]!=zon[(zon.length()-1)-q]){
					cnt++;
					q++;
				}
		}
		cout<<cnt;
	}
		
	
	return 0;
}


