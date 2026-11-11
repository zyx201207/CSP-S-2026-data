#include "bits/stdc++.h"
using namespace std;

int n,ans;
long long k;
int l;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>c;
		for(int i=k;i<k+l;i++)s[i]=c;
		k+=l;
	}
	if(k%2==1){
		for(int i=1;i<=(k-1)/2;i++){
			if(s[k/2-i]!=s[k/2+i])ans++;
		}
	}else{
		for(int i=1;i<=k/2;i++){
			if(s[k/2-i]!=s[k/2+i-1])ans++;
		}
	}
	cout<<ans;
	return 0;
}

