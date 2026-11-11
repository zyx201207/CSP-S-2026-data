#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n1, n2;
	char z1, z2;
	string c1, c2, s1, s2;
	bool flag=1;
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
//	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	
	z1 = s1[2];
	z2 = s2[2];
	n1 = (s1[0]-48)*10+(s1[1]-48);
	n2 = (s2[0]-48)*10+(s2[1]-48);
	
	if(c1!=c2){
		flag=0;
	}
	
	cout<<flag;
	
	if(n1!=n2){
		flag = 0;
	}
	
	cout<<flag;
	
	if(!((z1<='C'&&z2<='C') || (z1>='D' && z2>='D'))){
		flag = 0;
	}
	
	cout<<flag;
	
	int cha = z1-z2;
	char mx = max(z1, z2);
	
	if(!(abs(cha)==1 && mx!='D')){
		flag = 0;
	}
	
	cout<<flag;
	
	return 0;
} 
