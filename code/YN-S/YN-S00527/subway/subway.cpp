#include<bits/stdc++.h>
using namespace std;
const int max1 = 2147483647;
struct node{
	int data;
	double anh;
	node *next;
	int diff;
};
int *g;
int c;
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> c >> c >> c >> c;
	while(c --)
		cout << rand() << endl;
	return 0;
}
