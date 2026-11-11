#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string m,n;
	cin>>a>>m>>b>>n;
	int A=(m[0]-'0')*10+(m[1]-'0');
	int B=(n[0]-'0')*10+(n[1]-'0');
	int zuohao1=(int)(m[2]);
	int zuohao2=(int)(n[2]);
	if(zuohao1==5)zuohao1--;
	if(zuohao2==5)zuohao1--;
	if(a==b){
		cout<<1;
		if(A==B){
			cout<<1;
			if((zuohao1<=67&&zuohao2<=67)||(zuohao1>67&&zuohao2>67)){
				cout<<1;
				if((zuohao1==zuohao2-1)||(zuohao1==zuohao2+1))cout<<1;
				else cout<<0;
			}else cout<<"00";
		}
		else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}
