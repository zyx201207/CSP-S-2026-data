#include <bits/stdc++.h>
using namespace std;
struct stu{
	long long number ;
	char a;
}z[100010];
int A[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int Aj=1;
	for (int i=1;i<=n;i++){
		cin>>z[i].number>>z[i].a;
		for (int j=Aj;j<=Aj+z[i].number;j++){
			A[j]=int(z[i].a-'a');
		}
		Aj+=z[i].number;
	}
	int num=0;
	for (int i=1;i<=Aj/2;i++){
		if (A[i]!=A[Aj-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
