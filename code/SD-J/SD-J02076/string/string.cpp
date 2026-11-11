
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct nsplate{
	int ai;
	char ci;
}piece[1000000];
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	cin>>n;
	 
	for(int i=1;i<=n;i++){
		cin>>piece[i].ai>>piece[i].ci;
	}
	//sort(piece[1],piece[n]  
	for(int i=1;i<=n;i++){
		s=s+piece[i].ci;
	}
	if(n<=1){
	cout<<0;
	return 0;}
	if(n<=2){
		if(piece[0].ci==piece[1].ci)cout<<0;else cout<<1;
	}
	
	return 0;
}
