#include<bits/stdc++.h>
using namespace std;
int l,ll,sum;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	l=a.size();
	ll=c.size();
	if(a!=c){
		cout<<"0000";
		return 0;
	}else{
		sum+=1000;
		if(l+ll==4){
			if(b[1]==d[1]){
				sum+=100;
				if(b[2]<'D' && d[2]<'D' || b[2]>'C' && d[2]>'C'){
					sum+=10;
					if(b[2]=='F' && d[2]=='D' || b[2]=='D' && d[2]=='F'){
						sum+=1;
						cout<<sum;
						return 0;
					}else if((b[2]-'A'+1)==(d[2]-'A') || (b[2]-'A'-1)==(d[2]-'A')){
						sum+=1;
						cout<<sum;
						return 0;
					}else{
						cout<<sum;
						return 0;
					}
				}else{
					cout<<sum;
					return 0;
				}
			}else{
				cout<<sum;
				return 0;
			}
		}else if(l+ll==6){
			if(b[1]==d[1] && b[2]==d[2]){
				sum+=100;
				if(b[3]<'D' && d[3]<'D' || b[3]>'C' && d[3]>'C'){
					sum+=10;
					if(b[3]=='F' && d[3]=='D' || b[3]=='D' && d[3]=='F'){
						sum+=1;
						cout<<sum;
						return 0;
					}else if((b[3]-'A'+1)==(d[3]-'A') || (b[3]-'A'-1)==(d[3]-'A')){
						sum+=1;
						cout<<sum;
						return 0;
					}else{
						cout<<sum;
						return 0;
					}
				}else{
					cout<<sum;
					return 0;
				}
			}else{
				cout<<sum;
				return 0;
			}
		}else{
			cout<<sum;
			return 0;
		}
	}
	return 0;
}