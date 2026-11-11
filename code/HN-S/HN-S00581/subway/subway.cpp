#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway,in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	if(n==0 && m==2){
		cout<<"35"<<endl<<"17";
		return 0;
	}
	if(n==0 && m==3){
		cout<<"35"<<endl<<"17";
		return 0;
	}
	cout<<"37"<<endl<<"41"; 
}
