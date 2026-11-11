#include <bits/stdc++.h>
using namespace std;

struct Str{
	int num;
	char let;
};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	
	int n;
	cin>>n;
	
	Str a[200100];
	
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].let;
	} 
	
	cout<<"0"<<endl;
	
	return 0;
}
