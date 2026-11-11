#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	int n;
	long long m[1000000005],ant=0,num=0;
	string a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		ant+=m[i];
		cin>>b;
		for(int j=1;j<=m[i];j++){
			a+=b;
		}
	}
	int l=1,r=ant;
	while(r>=l){
		if(l==r){
			continue;
		}
		num++;
		l++;
		r--;
	}
	cout<<num;
	freopen("string.out","w",stdout);
	return 0;
}
