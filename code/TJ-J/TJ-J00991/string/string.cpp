#include<bits/stdc++.h>
using namespace std;
long long a,n,t,tt,x,y,cnt;
int ma;
string xx,yy,s,cc,s1,s2,aa[100005],aaa;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	tt=t;
//	for(int i=0;i<=t;i++){
//		cin>>aaa>>cc[i];
//		ma=max(ma,int(aaa.size()));
//		aa[i]=aaa;
//	}
	//if(ma<=9){
		while(t--){
//		a=stoi(aa[tt-t-1]),c=cc[tt-t-1];
		cin>>a>>c;
		//cout<<a<<' '<<c<<endl;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	if(s.size()%2==1){
		s1=s.substr(0,s.size()/2);
		s2=s.substr(s.size()/2+1,s.size()/2);
	}
	else{
		s1=s.substr(0,s.size()/2);
		s2=s.substr(s.size()/2,s.size()/2);
	}
	reverse(s2.begin(),s2.end());
	//cout<<s1<<' '<<s2<<endl;
	for(int i=0;i<s.size()/2;i++){
		if(s1[i]!=s2[i]){
			cnt++;
			//cout<<s1[i]<<' '<<s2[i]<<endl;
		}
	}
	
	//}
	
	cout<<cnt;
	return 0;
}
