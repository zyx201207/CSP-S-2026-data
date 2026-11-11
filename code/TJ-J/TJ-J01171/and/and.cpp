#include<bits/stdc++.h>
using namespace std;

long long m,n,k;
int s[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>s[i];
		if(k<s[i]){
			k=s[i];
		}
	}
	sort(s,s+m+1);
	cout<<s[n];
	return 0;s
}
