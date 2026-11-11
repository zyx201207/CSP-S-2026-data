#include<bits/stdc++.h>
using namespace std;
int a,ac,b,bc;
string aa,ab;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>ab;
	for(int i=0;i<2;i++){
		ac=ac*10+(aa[i]-48);
		bc=bc*10+(ab[i]-48);
	}
	if(a==b){
		cout<<1;
		if(ac==bc){
			cout<<1;
			if(('A'<=aa[2] and aa[2]<='C' and 'A'<=ab[2] and ab[2]<='C') or ('D'<=aa[2] and aa[2]<='F' and 'D'<=ab[2] and ab[2]<='F')){
				cout<<1;
				if(abs(aa[2]-ab[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	
	return 0;
} 

