#include<bits/stdc++.h>
using namespace std;
int n,m;
char c; 
string s;
long long sum,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		cin>>m>>c;
		sum+=m;
		while(m--){
			s+=c;
		}
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
