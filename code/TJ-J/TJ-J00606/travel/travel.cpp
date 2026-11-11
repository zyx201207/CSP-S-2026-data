#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+='1';
		bool flag=0;
		for(int i=0;i<b.size()-1;++i){
			if(b[i]!=d[i]){
				flag=1;
				ans+='0';
				break;
			}
		}
		if(flag==1){
			cout<<"1000";
			return 0;
		}
		else if(flag==0){
			ans+='1';
			int lenb=b.size();
			int lend=d.size();
			if((b[lenb-1]>='A' && d[lend-1]<='C') || (b[lenb-1]>='D' && d[lend-1]<='F')){
				ans+='1';
			}
			else{
				cout<<"1100";
				return 0;
			}
			if(abs(int(b[lenb-1]-d[lend-1]))==1){
				cout<<"1111";
			}
			else{
				cout<<"1110";
				return 0;
			}
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
