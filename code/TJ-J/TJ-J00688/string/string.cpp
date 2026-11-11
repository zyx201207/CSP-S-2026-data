#include<bits/stdc++.h>
using namespace std;
string s;int n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char a;
		cin>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	string ss=s;
	reverse(s.begin(),s.end());
	int ma=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=ss[i])ma++;
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
