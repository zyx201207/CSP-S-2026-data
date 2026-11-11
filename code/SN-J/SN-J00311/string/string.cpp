#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[1000000005];
	int n;
	cin>>n;
	string s;
	string c;
	for(int i=0;i<n;i++){
		cin>>a[i];
		getline(cin,c);
		string s1=c;
		int record=a[i];
		for(int j=0;j<record;j++){
			s=s+s1;
		}
	}
	int meter=s.size();
	int sum=0;
	int left=0;
	int right=meter-1;
	for(int i=0;i<meter;i++){
		if(left>=right) {
			cout<<sum;
		}else{ 
			if(left<right){
				if(s[left]!=s[right]){
					s[right]=s[left];
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
