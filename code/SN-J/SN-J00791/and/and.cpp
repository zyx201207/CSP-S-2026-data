//SN-J00791 余思弦 西安工业大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long a,b,s[1000019],d[1000019];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>s;
	}for(int i=1;i<=a;i++){
		d[s[i]]+=1;
	}
	int ma=-1;
	for(int i=1;i<=a;i++){
		if(ma<=d[i]) ma=d[i]
	}
	cout<<ma;
	return 0;
}
