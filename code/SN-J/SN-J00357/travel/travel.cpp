#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		for(int i=0;i<s1.size()-1;i++){
			r+=s1[i];
			x+=s2[i];
		}
		if(r==x){
			if(s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F'||s1[s1.size()-1]=='F'&&s2[s1.size()-1]=='D')
			cout<<1111<<endl;
			else if(s1[s1.size()-1]>='A'&& s1[s1.size()-1]<='C'){
				if(s1[s1.size()-1]-s2[s1.size()-1]==1||s1[s1.size()-1]-s2[s1.size()-1]==-1)cout <<1111<<endl;
				else cout<<1110<<endl;
			}
			else cout<<1100<<endl;
		}
		else cout<<1000<<endl;
	}
	else cout<<0000<<endl;
	return 0;
}

