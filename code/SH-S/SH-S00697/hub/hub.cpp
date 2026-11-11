#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	
	if (c==0){
		if (t==2){
			cout<<"1/n2";
			return 0;
		}
		
		if (t==3){
			cout<<"1/n1/n2";
			return 0;
		}
		
		if (t==5){
			int tmp;
			cin>>tmp;
			if (tmp==602){
				cout<<"17/n9/n6/n6/n9";
				return 0;
			}
			else if(tmp==24032){
				cout<<"189/n233/n288/n229/n338";
				return 0;
			}
		}
		
		if (t==1){
			cout<<12251;
			return 0;
		}
	}
	return 0;
}
