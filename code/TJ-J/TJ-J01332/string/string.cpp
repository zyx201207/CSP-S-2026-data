#include<bits/stdc++.h>
using namespace std;
int n;
//大概能拿一半 
//哦，不能了  
int a;
char c;
vector<char> str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> c;
		for(int i=0;i<a;i++){
			str.push_back(c);
		}
	}
	int s=str.size(),s2;
	if(s%2==0){
		s2=s/2-1;
	}else{
		s2=s/2;
	}
	int sum=0;
	for(int i=0;i<=s2;i++){
		if(str[i]!=str[s-1-i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
