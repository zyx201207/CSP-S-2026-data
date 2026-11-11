#include<bits\stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,b,v;
	char a,aa;
	cin>>n>>m>>a>>b>>v>>aa;
	int aaa=(int)(a-'A'+1),aaaa=(int)(aa-'A'+1);
	//cout<<aaa<<' '<<aaaa<<endl;
	if(n==b)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(m==v)cout<<1;
	else{
		cout<<"000";
		return 0;
	}  
	if((aaa<=3&&aaaa<=3)||(aaa>=4&&aaaa>=4)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(min(aaa,aaaa)+1==max(aaa,aaaa)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
