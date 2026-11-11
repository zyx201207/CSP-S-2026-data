# include<bits/stdc++.h>
using namespace std;
string s;
long long n,ant;
int main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		int a;
		char b;
		scanf("%d %c",&a,&b);
		for(int i=0;i<a;i++){
			s += b;
		}
	}
//	cout<<s;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ant++;
		}
	}
	printf("%lld",ant);
	return 0;
}

