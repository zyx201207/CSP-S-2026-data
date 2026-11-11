#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
string cc,ccc,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>s1>>ccc>>s2;
//	cout<<cc<<" "<<s1<<" "<<ccc<<" "<<s2<<"\n";
	if(cc==ccc){
		cout<<"1";
		string lie1=s1.substr(0,2),lie2=s2.substr(0,2);
//		cout<<lie1<<" "<<lie2<<"\n";
		if(lie1==lie2){
			cout<<"1";
//			cout<<s1[2]<<" "<<s2[2]<<"\n";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
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
	cout<<"\n";
	return 0;
}
