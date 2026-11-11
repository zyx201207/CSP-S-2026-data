#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int N=0,k=0,sum=0;
	string s1;
	char s2;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>k;
		cin>>s2;
		for(int j=0;j<k;j++){
			s1+=s2;
		}
	}
	int l=0,r=s1.size()-1;
	for(int j=1;j<=s1.size();j++){
		if(s1[l]!=s1[r]){
			sum++;	
		}
		l++;
		r--;
		if(l>r){
			break;
		}
	}
	cout<<sum;
	return 0;
}
