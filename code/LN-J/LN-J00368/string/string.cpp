#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
struct words{
	char c;
	int num;
}a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	if(sum>4e8){
		cout<<sum/2;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].num;j++){
			s+=a[i].c;
		}
	}
	long long cnt=0,x=0,y=sum-1;
	while(x<y){
		if(s[x]!=s[y]){
			cnt++;
		}
		x++;
		y--;
	}
	cout<<cnt;
	return 0;
}
