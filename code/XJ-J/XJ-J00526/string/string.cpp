#include <bits/stdc++.h>
using namespace std;
struct hvc{
	long long  num;
	string ch;
};
string s;
long long add;
long long mini,mini2;
hvc zzz[100005];
long long x;
long long y;
string fan;
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	long long  n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>zzz[i].num>>zzz[i].ch;
	}
		
	for(int i=0;i<n;i++){
		for(int j=0;j<zzz[i].num;j++){
			s=s+zzz[i].ch;
		}
	}
	

	
		
	for(int i=s.size()-1;i>=0;i++){
		fan=fan+s[i];
	}
	
	
	
	for(int i=1;i<s.size();i++){
		if(s[i]!=fan[i]){
			for(int j=0;j<n;j++){
				if(s[i]==zzz[j].ch){
					x=zzz[j].num;
				}
				if(fan[i]==zzz[j].ch){
					y=zzz[j].num;
				}
			}
			if(x>=y){
				fan[i]=s[i];}
			if(y>x){
				s[i]==fan[i];

		}
		add++;
	}
	cout<<add;
	return 0;
}
	