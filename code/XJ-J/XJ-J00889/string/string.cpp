#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int sum=0;
string x;
int n;
int l=1;
int m;
int h=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>x;
		h+=m;
		while(m--){
			s=s+x;	
		}
	}
	if(h%2==0){
		for(int i=1;i<=h/2;i++){
			a=s[i]+a;
		}
		for(int i=h/2+1;i<=h;i++){
			if(a[l]!=s[i])sum++;
			l++;
		}
	}
	else{
		for(int i=1;i<=(h+1)/2;i++){
			a=s[i]+a;
		}
		for(int i=(h+1)/2+1;i<=h;i++){
			if(a[l]!=s[i])sum++;
			l++;
		}
	}
	cout<<sum;
	return 0;
}