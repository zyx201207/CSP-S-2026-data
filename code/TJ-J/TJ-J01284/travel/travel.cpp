#include<bits/stdc++.h>
using namespace std;
struct travel{
	int chexiang,pai,hao;
	char zuowei;
};
travel r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ont","w",stdout);
	cin>>r.chexiang>>r.pai>>r.zuowei;
	cin>>x.chexiang>>x.pai>>x.zuowei;
	if(r.chexiang!=x.chexiang){
		cout<<"0000";
		return 0;
	}else{
		if(r.pai!=x.pai){
			cout<<1000;
			return 0;
		}else{
			if(r.zuowei<='C'&&x.zuowei<='C'&&r.zuowei>='A'&&x.zuowei>='A'){
				if(r.zuowei<x.zuowei&&r.zuowei+1==x.zuowei){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else if((r.zuowei=='D'&&x.zuowei=='F')||(r.zuowei=='F'&&x.zuowei=='D')){
				cout<<1111;
			}else{
				cout<<1100;
			}
		}
	}
	return 0;
} 
