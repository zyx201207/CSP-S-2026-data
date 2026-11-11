#include<bits/stdc++.h>
using namespace std;
	char chexiang1[15],zuowei1[15],chexiang2[15],zuowei2[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>chexiang1>>zuowei1>>chexiang2>>zuowei2;
	if(chexiang1[0]!=chexiang2[0] or chexiang1[1]!=chexiang2[1]){
		cout<<"0000";
		return 0;
	}
	else if(zuowei1[0]!=zuowei2[0] or zuowei1[1]!=zuowei2[1]){
		cout<<"1000";
		return 0;
	}
	else if((zuowei1[2]<='C' && zuowei1[2]>='A' && zuowei2[2]<='F' && zuowei2[2]>='D') or (zuowei1[2]<='F' && zuowei1[2]>='D' && zuowei2[2]<='C' && zuowei2[2]>='A')){
		cout<<"1100";
		return 0;
	}
	else if((zuowei1[2]=='A' && zuowei2[2]=='C') or (zuowei1[2]=='C' && zuowei2[2]=='A')){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
	return 0;
}
