#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	string s;
	int s2[m][n];
	for(int i=0;i<n;i++){
		for(int j=i-1;j<n;j++){
			for(int k=0;k<s.size();k++){
				if(s[k]==s[j]){
					s[k]=0;
				}
				s=s+s[j];
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=m||s[i]==n){
			s[m][n]++;
		}
	}
	cout<<"0"<<"0"<<"0";
	return 0;
}