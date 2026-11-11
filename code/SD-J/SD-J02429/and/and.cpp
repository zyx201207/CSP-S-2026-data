#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0;
	string s;
	cin>>n>>m;
	while(n!=0){
		s[cnt]=char(n%2);
		n=n/2;
		cnt++;
	}
	for(int i=0;i<cnt;i++){
		cout<<s[i];
	}
	cout<<"\n"<<cnt+1;
	return 0;
} 
