#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);*/
	
	string c1,s1,c2,s2;
	int f=0,ff=0;
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	//2
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		//3
		for(int i='A';i<='C';i++){
			for(int j='A';j<='C';j++)if(s1[2]==i&&s2[2]==j&&i!=j)f=1;
		}
		if(s1[2]=='D'&&s2[2]=='F' || s1[2]=='F'&&s2[2]=='D')f=2;
		if(f!=0)cout<<1;
		if(f==0)cout<<0;
	}
	else cout<<0<<0;
	//4
	for(int i='A';i<='C';i++){
		if(s1[2]==i&&s2[2]==i+1&&i+1<'D')ff=1;
		if(s1[2]==i&&s2[2]==i-1&&i-2>='A')ff=1;
		if(ff==1) break;
	}
	if(f==2||ff==1) cout<<1;
	else cout<<0;
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}