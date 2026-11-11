//kao hao:SH-J00674   xing ming:wang ge   xue xiao:yan an pei zhi zhong xue
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,q = 0,l = 0;
	cin>>n;
	char bs[200010];
	for(int i = 0;i<n;i++){
		int p;
		cin>>p;
		char o;
		cin>>o;
		for(int j = q;j<p;j++){
			bs[j] = o;
		}
		q = j;
		l+=p;
	}
	int s = l-1;
	bool flag = 1;
	for(int i = 0;i<l/2;i++){
		if(bs[i] != bs[s]){
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		cout<<0;
		return 0;
	}
	int g = l%2;
	char s[200010],r[200010];
	for(int i = 0;i<g;i++){
		s[i] = bs[i];
	}
	for(int i = g;i<l;i++){
		r[i] = bs[i];
	}
	int h = 0;
	for(int i = 0;i<g;i++){
		if(s[i] != r[i]){
			h++;
		}
	}
	cout<<h;
	return 0;
}
