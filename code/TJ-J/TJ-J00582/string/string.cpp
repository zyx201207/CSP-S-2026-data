#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],n,cnt;
char c[N];
string s;
/*
2
2 a
3 a
*/
int main(){
	freopen("string4.in","r",stdin);
	freopen("string4.out","w",stdout);
	cin>>n; 
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])++cnt;
	} 
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
