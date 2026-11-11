#include<bits/stdc++.h>
using namespace std;
long long a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<"1";
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
			cout<<"1";
			if((int (aa[2])<='C'&&int (bb[2])<='C')||(int (aa[2])>='D'&&int (bb[2])>='D')){
				cout<<"1";
				if(int(aa[2])+1==int(bb[2])||int(aa[2])-1==int(bb[2])){
					cout<<"1";
				}
				else{
			cout<<"0";
		} 
			}
			else{
			cout<<"00";
		} 
			
		}
		else{
			cout<<"000";
		} 
		
	}
	else{
		cout<<"0000";
	}

	return 0;
}
