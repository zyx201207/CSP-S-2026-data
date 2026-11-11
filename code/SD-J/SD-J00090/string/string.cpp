#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
struct node{
	ll a;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		int a1,a2;
		char c1,c2;
		cin>>a1>>c1>>a2>>c2;
		if(c1==c2){
			cout<<0<<endl;
			return 0;
		}
		cout<<min(a1,a2)<<endl;
		return 0;
	}
	bool flag=0;
	string str="";
	cin>>a[1].a>>a[1].c;
	for(int i=1;i<=a[1].a;i++){
		str+=a[1].c;
	}
	for(int i=2;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		for(int j=1;j<=a[i].a;j++){
			str+=a[i].c;
		}
		if(a[i].c!=a[i-1].c){
			flag=1;
		}
	}
	if(flag==0){
		cout<<0<<endl;
		return 0;
	}
	ll len=str.size();
	ll ans=0;
	for(int i=0;i<len/2;i++){
		if(str[i]!=str[len-i-1]) ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
