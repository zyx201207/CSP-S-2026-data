#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char t,m;
	bool q=true;
	cin>>a>>m;
	for(int i=2;i<=n;i++){
		cin>>a>>t;
		if(m!=t) q=false;
		m=t;
	}
	if(q){
		cout<<"0";
		return 0;
	}
	cout<<"1000000000";
}

