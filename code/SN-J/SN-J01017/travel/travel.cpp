#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int len1=c1.size(),len2=s1.size();
	bool f=0;
	for(int i=0;i<len1;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000\n";
			return 0;
		}else{
			f=1;
		}
	}
	if(f==1) cout<<1;
	f=0;
	for(int i=0;i<len2-1;i++){
		if(s1[i]!=s2[i]){
			f=0;
			cout<<"000";
			return 0;
		}
		else{
			f=1;
		}
	}
	if(f==1) cout<<1;
	if(s1[len2-1]<'D'&&s2[len2-1]<'D') cout<<1;
	else cout<<0;
	if(min(s1[len2-1],s2[len2-1])+1<'D'&&min(s1[len2-1],s2[len2-1])+1==max(s1[len2-1],s2[len2-1])){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
