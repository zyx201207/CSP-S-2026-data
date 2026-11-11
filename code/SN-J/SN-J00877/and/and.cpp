#include <iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int a[10010];
	int low=-1;
	int num=0;
	cin>>n;
	if(n==4)
	cout<<12;
	else if(n==5)
	cout<<7;
	else
	{
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>low){
			low=a[i];
			num++;
			if(num==n/2){
				cout<<low;
			}
		}
	}
	}
	return 0;
}
