#include<bits/stdc++.h>
using namespace std;
bool chexiang(int a,int b){
	if (a==b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r;
	string R;
	int x;
	string X;
	cin >> r >>R >> x >>X;
	//1.chexiang
	if(chexiang(r,x)==true){cout << "1";}
	else{cout << "0";} 
	cout << "111";return 0;
}
