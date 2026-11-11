#include<bits/stdc++.h>
using namespace std;
char tex[200200];
long long num[200200],n,m,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i]>>tex[i];
	}
	vector<char> a;
	for(int i=0;i<n;i++){
		for(int j=0;j<num[i];j++){
			a.push_back(tex[i]);
		}
	}
	if(a.size()%2==0){
		int b=a.size()/2;
	}
	else{
		int b=a.size()/2+1;
	}
	for(int i=a.size()-1;i>=b;i--){
		if(a[i]!=a[j]){
			m++;
		}
		j++;
	}
	cout<<m;
	return 0;
}
