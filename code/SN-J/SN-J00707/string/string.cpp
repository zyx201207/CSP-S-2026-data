//dujingqi jiandafuzhong SN-J00707
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num;
	int a;
	string c,s;
	cin>>n;
	int n1=n;
	while(n1>0){
		cin>>a;
		cin>>c;
		for(int i=1; i<=a; i++){
			s+=c;
		}
		n1--;
	}
	int l,r=n-1;
	for(int l=0; l<=n/2-1; l++){
		if(s[l]!=s[r]) num++;
		r--;
	}
	cout<<num;
	return 0;
}
