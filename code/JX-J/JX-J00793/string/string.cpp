#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b=0;
char c[100005];
string s;
int main(){
feropen("string.in","r",stdin);
feropen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
}
	for(int i=1;i<=n;i++){
	if(c[i]==c[i+1])b++;
	}
	if(b==n-1)cout<<"0";
	return 0;
}

