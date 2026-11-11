#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f = 0,f1 = 0,f0 = 0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int ans1 = (s1[0]-'0')*10+(s1[1]-'0'),ans2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(ans1==ans2){
		cout<<1;
		f=1;
		f0=1;
	}else{
		cout<<0;
	}
	int cnt1 = s1[2]-'A',cnt2 = s2[2]-'A';
	if(cnt1<=2&&cnt2<=2&&f0==1){
		cout<<1;
		f1 = 1;
	}else if(cnt1>=3&&cnt2>=3&&f0==1){
		cout<<1;
		f1 = 1;
	}else{
		cout<<0;
	}
	if(f==0||f1==0){
		cout<<0;
	}else if(cnt1==cnt2+1||cnt2==cnt1+1){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
