#include<bits/stdc++.h>
using namespace std;
long n,a[200001];
char c[200001];
string s;
int main(){
	//freopen("string.in","r",stdin);
//	freopen("string.out","W",stdout);
	int num;
	cin >>num;
	
	for (long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			num++;
		}
	}
    cout<<num/2;
	
	return 0;
	
}
