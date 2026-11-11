#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		for(int i=1;i<=a;i++){
			S+=c;
		}
	}
	unsigned long long ans=0;
	for(int i=0;i<S.size()/2;i++){
		if(S[i]!=S[S.size()-1-i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}