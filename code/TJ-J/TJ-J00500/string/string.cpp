#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long t[278],c;
char k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long mx=0;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		t[int(c)]+=a;
	}
	int pd=0;
	for(int i='a';i<='z';i++){
		if(mx<t[i]){
			mx=t[i];
			k=char(i);
		}
		if(t[i]>0)pd++;
	}
	if(pd==1){
		cout<<0;
		return 0;
	}
	int smx=0;
	char sk;
	for(int i='z';i>='a';i--){
		if(t[i]<=mx&&i!=k&&t[i]>smx){
			smx=t[i];
			sk=char(i);
		}
	}
	bool x=1;
	for(int i='a';i<='z';i++){
		if(i!=k&&i!=sk&&t[i]!=0){
			c+=t[i];
			t[i]=0;
			x=0;
		}
	}
	if(!x)cout<<c+(mx/2);
	else cout<<c+mx;
	return 0;
}
