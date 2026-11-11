#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));cout<<4<<'\n';
	for(int i=1;i<=4;i++){
		int c=rand()%4+1;char ch=rand()%4+'a';
		cout<<c<<' '<<ch<<'\n';
	}
	return 0;
}

