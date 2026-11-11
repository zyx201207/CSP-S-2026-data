#include<bits/stdc++.h>
using namespace std;

const long long N=100000;
long long a[N+10];
long long cha[N+10];
int mi[N+10];
int wz[N+10];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		cha[i]=a[i+1]-a[i];
	}
	
	int num=-1;
	int zm=0;
	for(int i=1;i<=n;i++){
		int num1=0;
		for(int j=i;j<=n;j++){
			zm+=cha[j-1];
			num1++;
			if(zm>m){
				num1--;
				num=max(num,num1);
				break;
			}
		}
	}
	cout<<num;

	return 0;
}
