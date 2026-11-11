#include<bits/stdc++.h>
#include<string>
using namespace std;
long long  n;
string s;
char c[1000005];
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	long long a[n+5],num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	int b=1;//³öÎÊÌâ; 
	for(int i=b;i<=n;i=b){	
		s[i]=c[i];
		a[i]--;
		if(a[i]==0) b++;
	}
	int sum=0;
	long long lens=s.length();
		for(int i=1;i<=lens/2;i++){
			if(s[i]!=s[lens-i+1]) sum++;
		}
	
	cout<<sum;
	
	return 0;
}
