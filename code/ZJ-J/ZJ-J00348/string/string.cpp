#include<bits/stdc++.h>
using namespace std;
string s=" ",s1;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		scanf("%d",&a);
		cin>>c;
		l+=a;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=1;i<=l;i++){
		s1[i]=s[l-i+1];
	}
	long long cnt=0;
	for(int i=1;i<=l;i++){
		if(s1[i]!=s[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}