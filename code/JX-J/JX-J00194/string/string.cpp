#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long sum=0;
int idx=0;
char c[100006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int idx=0;
	for(int i=0;i<n;i++){
		int d;
		char goal;
		cin>>d>>goal;
		for(int j=idx;j<idx+d;j++){
			c[j]=goal;
		}
		idx+=d;
	}
	int l=0,r=idx-1;
	int mid=idx/2;
	if((2*mid)==idx){
		while(l<mid&&r>=mid){
			if(c[l]!=c[r]){
				sum++;
			}
			l++,r--;
		}
	}
	else{
		while(l<mid&&r>mid){
			if(c[l]!=c[r]){
				sum++;
			}
			l++,r--;
		}
	}
	cout<<sum;
	return 0;
}
