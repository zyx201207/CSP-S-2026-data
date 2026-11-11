#include<bits/stdc++.h>
using namespace std;
long long n,x,sum,num;
string s,s1,s2;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		sum+=x;
		for(int i=1;i<=x;i++){
			s=s+c;
		}
	}
	sum/=2;
	s1=s.substr(0,sum);
	s2=s.substr(sum+1);
	for(int i=0;i<sum;i++){
		if(s1[i]!=s2[s2.size()-i-1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
