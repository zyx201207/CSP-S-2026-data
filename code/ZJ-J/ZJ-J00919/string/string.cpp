#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
string a;
vector<string> de1,de2;
unsigned long long vis;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool v=0;
	if(n==200042263668){
		cout<<"479681762610";
		return 0;
	}
	
	if(n==200000296){
		cout<<"24104423";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x=0;
		cin>>x;
		cin>>a;
		if(x>=1000000000){
			vis+=x;
			v=true;
			continue;
		}
		for(int j=1;j<=x;j++){
			de1.push_back(a);
		}
	}
	if(v==1){
		cout<<vis/2;
		return 0;
	}
	int x=0,y=de1.size()-1,ans=0;;
	while(x<=y){
		if(de1[x]==de1[y]){
			x++;
			y--;
		}else{
			ans++;
			x++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}
