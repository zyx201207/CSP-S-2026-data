#include<bits/stdc++.h>
using namespace std;
string s;
int minn1=0,minn2=0,min;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	if(n==1){
		cout<<0<<endl;
	}
	//ÕâÌâÊ«ÈË? 
	return 0;
}
