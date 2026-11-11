#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ss1,ss2;
int main (){
	freopen("travel.in","r",strin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout <<1;
		long long sum=0;
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				sum++;
			}
		}
		if(sum==2){
			cout <<1;
			ss1="0";
			ss2="0";
			for(int i=2;i>1;i--){
				ss1=s1[i];
				ss2=s2[i];
			}
			int f=0;
			if(ss1=="A"){
				if(ss2=="B"||ss2=="C"){
					cout<<1;
					f++;
				}
			}else if(ss1=="B"){
				if(ss2=="A"||ss2=="C"){
					cout<<1;
					f++;
				}
			}else if(ss1=="C"){
				if(ss2=="A"||ss2=="B"){
					cout<<1;
					f++;
				}
			}else if(ss1=="D"){
				if(ss2=="E"){
					cout<<1;
					f++;
				}
			}else if(ss1=="E"){
				if(ss2=="D"){
					cout<<1;
					f++;
				}
			}
			if(f==0){
				cout <<"00";
				return 0;
			}else{
				f=0;
				if(ss1=="A"){
					if(ss2=="B"){
						cout <<1;
						f++;
					}
				}else if(ss1=="B"){
					if(ss2=="A"||ss2=="C"){
						cout <<1;
						f++;
					}
				}else if(ss1=="C"){
					if(ss2=="B"){
						cout <<1;
						f++;
					}
				}else if(ss1=="D"){
					if(ss2=="E"){
						cout <<1;
						f++;
					}
				}else if(ss1=="E"){
					if(ss2=="D"){
						cout <<1;
						f++;
					}
				}
				if(f==0){
					cout <<0;
				}
			}
		}else{
			cout <<"000";
			return 0;
		}
	}else{
		cout <<"0000";
		return 0;
	}
	return 0;
}