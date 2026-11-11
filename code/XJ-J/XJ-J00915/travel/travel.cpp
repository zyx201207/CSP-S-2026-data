#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x;
	cin>>x;
	for(int i=1;i<x;i++){
		if(x<=9) x++;
	}
	cout<<x;
	return 0;
}