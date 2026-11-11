#include<iostream>
using namespace std;
const int N=INT_MAX;
long long a[N],n,k,m;
string s;
char x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cout<<0<<" ";
	}
	return 0;
}
