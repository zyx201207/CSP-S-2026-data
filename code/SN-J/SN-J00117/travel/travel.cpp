#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1=0,a2=0,a3=0,a4=0;
	for(int i=0;i<2;i++){
		if(i==1 && c1[i]==c2[i]){
			a1+=1;
			break;
		}
		if(c1[i]==c2[i]){
			continue;
		}
	}
	if(a1==0){
		cout << a1 << a2 << a3 << a4;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(i==1 && s1[i]==s2[i]){
			a2+=1;
			break;
		}
	}
	if(a2==0){
		cout << a1 << a2 << a3 << a4;
		return 0;
	}
	int b1=s1[2],b2=s2[2];
	if(b1<=67 && b1>=65){
		if(b2<=67 && b2>=65){
			a3+=1;
		}
	}else if(b1==68 || b1==69){
		if(b2==68 || b2==69){
			a3+=1;
		}
	}
	if(a3==0){
		cout << a1 << a2 << a3 << a4;
		return 0;
	}
	if((b1==65 && b2==66) || (b1==66 && b2==67) || (b1==66 && b2==65) || (b1==67 && b2==66)){
	    a4+=1;	
	}else if((b1==68 && b2==69) || (b1==69 && b2==68)){
		a4+=1;
	}
	if(a4==0){
		cout << a1 << a2 << a3 << a4;
		return 0;
	}
	cout << a1 << a2 << a3 << a4;
	return 0;
}
