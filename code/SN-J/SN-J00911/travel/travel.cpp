#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen(" travel.in","r",stdin);
	freopen(" travel.out","w",stdout);
	int c1,i,s1,s2;
	int c2;
	cin>>c1>>c2;
	if(c1==c2){
		cout<<1;
		cin>>s1>>s2;
		for(i=1;i<=2;i++){
			if(s1=s2+1){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0<<endl;
	}
	
	return 0;
}
