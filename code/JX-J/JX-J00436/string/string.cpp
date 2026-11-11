#include<bits/stdc++.h>
using namespace std;
int n,a[10005],x,s=0;
char y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s++;
			a[s]=y-'0';
			//cout<<a[s];
		}
	}
	n=s;
	//cout<<endl<<n<<"@#$%\n";
	s=0;
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[n-i+1]) s++;
		//cout<<s<<" '^' biu~~\n"<<i<<"' '";
	}
	cout<<s;
	/*  /\_/\
	   (='^'=) */
	return 0;
}
