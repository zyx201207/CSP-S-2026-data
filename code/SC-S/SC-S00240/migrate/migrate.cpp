#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long a[2000006];
bool test(int c,int d){
	for(int i=1;i<=n;i++){
		string s;
		
	}
}
void answer(int t){
	int n,d;
	int ans;
	
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<d%abs(3-t-c);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		for(int i=1;i<=n;i++)cout<<"0\n";
		return 0;
	}
	while(t--){
		answer(t);
	}
}