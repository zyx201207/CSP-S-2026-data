#include<bits/stdc++.h>
using namespace std;
int n;
int ts=10000000,cnt=0;
string s;
int a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(a<ts) ts=a;
		cnt+=a;
		for(int j=1;j<=a;j++){
		s+=c;
		}
	}
	if(n==2){
		cout<<ts;
		return 0;
	}
	if(cnt%2==0){
		cout<<(cnt/2);
		return 0;
	}
	if(cnt%2!=0){
		cnt=cnt-1;
		cout<<(cnt/2);
	}
	return 0;
}
