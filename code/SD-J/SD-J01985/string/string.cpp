#include<bits/stdc++.h>
using namespace std;
string p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	bool f=0,dl=0;
	char kld=0;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		if(!f){
			kld=c;
			f=1;
		} 
		if(kld!=c) dl=1;
		for(int i=0;i<a;i++) p+=c;
	}
	string ans=p;
	long long s=ans.size()/2,c=0,bf=0;
	reverse(p.begin(),p.end());
	if(!dl||n==1||p==ans){
		cout<<0;
		return 0;
	}
	for(int i=0;i<ans.size();i++){
		if(p[i]!=ans[i]) bf++;
	}
	cout<<bf/2;
	
	return 0;
}
