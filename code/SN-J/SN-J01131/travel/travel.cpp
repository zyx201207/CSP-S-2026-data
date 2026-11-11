#include<bits/stdc++.h>
using namespace std;
string c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s;
	int n;
	for(int i=1;i<=n;i++){
	    cin>>c[i];
	}
	int len=s.size();
	for(int j=1;j<=len;j++){
	    cin>>s[j];
    }
	int c1=c[0];
	int s1=s[1];
	int c2=c[2];
	int s2=s[3];
	if(c1!=c2){
		cout<<"0000";
	}
	return 0;
} 
