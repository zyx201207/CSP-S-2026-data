#include<bits/stdc++.h>
using namespace std;
string s[200009];
int x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long f=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char d;
		cin>>a>>d;
		for(int j=0;j<a;j++){
			s[i][j]=d;	
		}
		x[i]=a;
	}
	int c=n;
	int k=x[c]-1;
	for(int i=1;i<=(n+1)/2;i++){
		for(int j=0;j<=x[i]-1;j++){
			if(s[i][j]!=s[c][k]){
				s[c][k]=s[i][j];
				f++;
			}
			if(k-1>=0)
				k--;
			else{
				c--;
				k=x[c]-1;
			}
		}
	}
	cout<<f;
	return 0;
} 
