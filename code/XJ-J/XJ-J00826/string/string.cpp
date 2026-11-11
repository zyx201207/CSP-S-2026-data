#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char a;
	long long n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>a;
		for(int i=1;i<=m;i++){
			s+=a;
		}
	}
	int right=s.size()-1,left=0,cnt;
	while(right!=left){
		if(s[left]!=s[right]){
			s[left]=s[right];
			cnt++;
		}
		left++;
		right--;
	}
	
	cout<<cnt;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
