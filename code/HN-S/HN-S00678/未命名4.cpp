#include<bits/stdc++.h>
using namespace std;
vector<long long>a;

int main(){
	long long i=0;
	while(1){
		long long t;
		cin>>t;
		if(t==999)break;
		else a.push_back(t);
		i++;
	}for(int j=0;j<i;j++)cout<<a[j]<<',';
	cout<<endl<<i;
}/*6800625333
6247500
6242502
4998
9994
0
0
0
2
1
0
2
3
6
0
2


*/

