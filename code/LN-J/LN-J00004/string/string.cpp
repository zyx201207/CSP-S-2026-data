#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    s='0';
    int l=0;
    for(int i=1;i<=n;i++){
		int m;
		char a;
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
		l+=m;
	}
	int t=0;
	for(int i=1;i<l/2;i++){
		if(s[i]!=s[s.size()-i]){
			t++;
		}
	}
	cout<<t;
    return 0;
 }
