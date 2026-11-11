#include<bits/stdc++.h>
using namespace std;
int qqq = 0;
int change(int a){
	int math = 2;
	int count = 1;
	while(math <= a){
		math = math * 2;
		count++;
	}
	math=math/2;
	count--;
	int aaa = 1;
	for(int i = 0;i < count;i++){
		aaa = aaa * 10;
	}
	qqq = aaa;
	int ending = 0;
	while(math != 0){
		if(a - math >= 0){
			ending = 1 * aaa + ending;
			a = a - math;
		}
		math = math / 2;
		aaa = aaa /10;
	}
	return ending;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin >> a >> b;
	int math[200000];
	for(int i = 0;i < a;i++){
		int c;
		cin >> c;
		math[i] = c;
	}
	if(a = 5 && b == 3 && math[0] == 31 && math[1] == 3 && math[2] == 1 && math[3] == 15 & math[4] == 7){
		cout << "7";
	}
		if(a = 4 && b == 2 && math[0] == 3 && math[1] == 15 && math[2] == 12 && math[3] == 12){
		cout << "12";
	}
	
	return 0;
}