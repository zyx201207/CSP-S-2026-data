#include<bits/stdc++.h>
using namespace std;
char a, b;
int n,k,l;
int m[1000];
	int g;
string c;
int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);	
cin>>n;
g=1;
for(int i=1;i<=n;i++){
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		m[g]=b;
		}
		g++;
	}
	k=g/2+1;
for(int i=1;i<=k;i++){
	if(m[i]!=m[g-i])
	l++;
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}


