#include <bits/stdc++.h>
using namespace std;
string s="                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ";
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	char a1;
	int a;
	
	int p=0;
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++){
		cin>>a>>a1;
		sum+=a;
		for (int i=1;i<=a;i++){
			s[p]=a1;
			p++;
		}
	}
	cout<<s;
	int mid=sum/2;
	if (sum%2==1){
		mid++;
		for (int i=1;i<=n/2;i++){
			int gggggg=1;
		}
	}
	
	return 0;
}
