#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],s[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	bool flag=true;
	int num=0;
	while (n>0){
		for (int i=0;i<n;i++){
			for (int j=0;j<i;j++){
				if (s[i]==s[j]){
					flag=false;
				}
			}
			if (flag){
				s[i]=a[i];
				}
		}
		n--;
		if (s[s.size-1]==m){
			num+=1;
		}
	}
	cout<<num<<" "<<n;
	return 0;
}
