#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,d;
	int b,e;
	char c,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(a!=d){
		cout<<"0000";
		return 0;
	}
	if(b!=e){
		cout<<"1000";
		return 0;
	}
	if(('A'<=c && 'C'>=c)){
		if(f>='D'){
			cout<<"1100";
			return 0;
		}
		if(abs(c-f)!=1){
			cout<<"1110";
			return 0;
		}
	}
	if(('A'<=f && 'C'>=f)){
		if(c>='D'){
			cout<<"1100";
			return 0;
		}
		if(abs(c-f)!=1){
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
