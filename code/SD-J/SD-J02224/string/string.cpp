#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a,sum=0;
char ch;
void add(long long a,char c){
	for(int i=1;i<=a;i++)s+=c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int l=0,r=-1;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		add(a,ch);
		r+=a;
	}
	
	while(l<=r){
		
		if(s[l]!=s[r])sum++;
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}

